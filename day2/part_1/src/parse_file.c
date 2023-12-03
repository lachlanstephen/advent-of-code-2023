/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:17:52 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/03 03:25:36 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_conundrum.h"

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}

int	find_value(char *line)
{
	int	i;
	int	length;
	int	nums;

	i = -1;
	length = ft_strlen(line);
	nums = 0;

// iters = { count, start, game_id, result}
void	parse_values(int fd)
{
	char		temp;
	static char	line[10000];
	int			iters[4];
	int			i;

	i = -1;
	while (++i <= 3)
		iters[i] = 0;
	while ((read(fd, &temp, 1) != 0))
	{
		if (temp == ':')
			iters[1] = iters[0];
		if (temp == '\n')
		{
			line[(iters[0])] = '\0';
			iters[3] += find_value(&line[(iters[1])]);
			iters[0] = 0;
			iters[1] = 0;
		}
		else
		{
			line[(iters[0])] = temp;
			iters[0]++;
		}
	}
	ft_print_num(iters[3]);
	ft_putchar('\n');
}
