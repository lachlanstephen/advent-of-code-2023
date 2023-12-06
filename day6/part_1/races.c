/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:51:51 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/06 16:37:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_win(int speed, int time_rem, int distance)
{
	if (speed * time_rem > distance)
		return (1);
	return (0);
}

void	win_calc(int *times, int *min_dist, int amount)
{
	int	total;
	int	i;
	int	count;
	int	speed;

	total = 1;
	i = 0;
	count = 0;
	while (i < amount)
	{
		speed = 0;
		while (speed < times[i])
		{
			count += check_win(speed, times[i] - speed, min_dist[i]);
			speed++;
		}
		total *= count;
		count = 0;
		i++;
	}
	printf("%d\n", total);
}

int	main(void)
{
	int	race_amount;
	int	times[] = { 56, 97, 78, 75 };
	int	min_dist[] = { 546, 1927, 1131, 1139 };

	race_amount = 4;
	win_calc(times, min_dist, race_amount);
	return (0);
}
