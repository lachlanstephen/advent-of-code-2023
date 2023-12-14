/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosmic_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:18:18 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/14 23:51:00 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosmic_expansion.h"

static void	ft_count_row_space(char **init_gal, int *count)
{
	int		i;
	int		j;
	bool	gal_exist;

	i = -1;
	count[0] = 0;
	while (++i < ROW_AMOUNT)
	{
		j = -1;
		gal_exist = false;
		while (init_gal[i][++j] != 0)
		{
			if (init_gal[i][j] == '#')
			{
				gal_exist = true;
				break ;
			}
		}
		if (gal_exist != true)
			count[0]++;
	}
	count[0] += i;
}

static void	ft_count_col_space(char **init_gal, int *count)
{
	int		i;
	int		j;
	bool	gal_exist;

	i = 0;
	j = -1;
	count[1] = 0;
	while (init_gal[i][++j] != 0)
	{
		gal_exist = false;
		while (i < ROW_AMOUNT)
		{
			if (init_gal[i][j] == '#')
			{
				gal_exist = true;
				break ;
			}
			i++;
		}
		if (gal_exist != true)
			count[1]++;
		i = 0;
	}
	count[1] += j;
}

// Used an int array to store the many iterators required
// int	iters[5] = { h, i, j, k, l }
// i and j step through the initial galaxy
// k and l step through the expanded galaxy
// h is used to check whether the initial galaxy's 
// 		current column contains any galaxies
static void	populate_gal(char **init_gal, char **exp_gal, int *count)
{
	int		iters[5];
	bool	gal_exists_col;
	bool	gal_exists_row;

	iters[1] = -1;
	iters[3] = -1;
	gal_exists_col = false;
	gal_exists_row = false;
	while (++iters[3] >= 0 && ++iters[1] < ROW_AMOUNT)
	{
		iters[2] = -1;
		iters[4] = -1;
		gal_exists_row = false;
		while (++iters[4] >= 0 && init_gal[(iters[1])][++(iters[2])] != 0)
		{
			iters[0] = -1;
			gal_exists_col = false;
			while (++iters[0] < ROW_AMOUNT)
			{
				if (init_gal[(iters[0])][(iters[2])] == '#')
				{
					gal_exists_col = true;
					break ;
				}
			}
			if (gal_exists_col != true)
				exp_gal[(iters[3])][(iters[4])++] = '.';
			if (init_gal[(iters[1])][(iters[2])] == '#')
				gal_exists_row = true;
			exp_gal[(iters[3])][(iters[4])] = init_gal[(iters[1])][(iters[2])];
		}
		exp_gal[(iters[3])][(iters[4])] = '\0';
		if (gal_exists_row != true)
		{
			iters[3]++;
			iters[4] = -1;
			while (++iters[4] < count[1] - 1)
				exp_gal[(iters[3])][(iters[4])] = '.';
			exp_gal[(iters[3])][(++iters[4])] = '\0';
		}
	}
}

char	**galaxy_expansion(char **init_gal, int *count)
{
	int		i;
	char	**exp_gal;

	i = 0;
	ft_count_row_space(init_gal, count);
	ft_count_col_space(init_gal, count);
	exp_gal = malloc(sizeof(char *) * count[0]);
	if (exp_gal == NULL)
		ft_prn_error(2);
	while (i < count[0])
	{
		exp_gal[i] = malloc(sizeof(char) * count[1] + 1);
		if (exp_gal[i] == NULL)
			ft_free_error(exp_gal, i);
		i++;
	}
	populate_gal(init_gal, exp_gal, count);
	return (exp_gal);
}
