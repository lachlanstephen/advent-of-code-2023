/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:51:51 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/06 16:09:57 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_win(long speed, long time_rem, long distance)
{
	if (speed * time_rem > distance)
		return (1);
	return (0);
}

void	win_calc(long times, long min_dist)
{
	long	total;
	long	speed;

	total = 0;
	speed = 0;
	while (speed < times)
	{
		total += check_win(speed, times - speed, min_dist);
		speed++;
	}
	printf("%lu\n", total);
}

int	main(void)
{
	long	time;
	long	min_dist;

	time = 56977875;
	min_dist = 546192711311139;
	win_calc(time, min_dist);
	return (0);
}
