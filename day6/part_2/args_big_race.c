/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_big_race.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:13:41 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/06 16:28:57 by darkwater        ###   ########.fr       */
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

char	*valid_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	str[i] = '\0';
	return (str);
}

long	ft_atoul(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	str = valid_chars(str);
	while (str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

int	main(int argc, char *argv[])
{
	long	time;
	long	min_dist;

	if (argc != 3)
	{
		printf("Wrong argument amount!\n");
		return (1);
	}
	time = ft_atoul(argv[1]);
	min_dist = ft_atoul(argv[2]);
	if (time == 0 || min_dist == 0)
	{
		printf("Please input valid positive values!\n");
		return (1);
	}
	win_calc(time, min_dist);
	return (0);
}
