/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosmic_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:18:18 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:22 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosmic_expansion.h"

static int	*ft_count_space(char init_gal[140][142])
{
	int		i;
	int		j;
	int		count[2];
	bool	gal_exist;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	while (i < 140)
	{
		j = 0;
		while (init_gal[i][j] != 0)
		{
			if (init_gal[i][j] == '#')
			{
				gal_exist = true;
				break ;
			}
			j++;
		}
		if (gal_exist != true)
			count[0]++;
		i++;
	}
	return (count);
}

char	**galaxy_expansion(char init_gal[140][142])
{
	int	i;
	int	j;
	int	count[2];
	bool	gal_exist;
	char	**exp_gal;

	i = 0;
	count = ft_count_space(init_gal);

	while (i < 140)
	{
		j = 0;
		while (init_gal[i][j] != 0)
		{
			if (init_gal[i][j] == '#')
			{
				gal_exist = true;
				break ;
			}
			j++;
		}
		if (gal_exist != true)
			count++;
		i++;
	}
