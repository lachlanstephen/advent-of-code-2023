/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:02:33 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/13 05:33:26 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosmic_expansion.h"

long	calc_distance(char **exp_gal, int gal_y, int gal_x, int *count)
{
	int		i;
	int		j;
	long	distance;

	distance = 0;
	i = gal_y - 1;
	while (++i < count[0])
	{
		if (gal_y == i)
			j = gal_x;
		else
			j = - 1;
		while (exp_gal[i][++j] != 0)
		{
			if (exp_gal[i][j] == '#')
				distance += abs(i - gal_y) + abs(j - gal_x);
		}
	}
	return (distance);
}

void	total_gal_distance(char **exp_gal, int *count)
{
	int		i;
	int		j;
	long	total;

	i = -1;
	total = 0;
	while (++i < count[0])
	{
		j = -1;
		while (exp_gal[i][++j] != 0)
		{
			if (exp_gal[i][j] == '#')
				total += calc_distance(exp_gal, i, j, count);
		}
	}
	printf("\nTotal Distance between galaxies: %lu\n", total);
}
