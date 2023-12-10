/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:37:19 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/10 23:36:54 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_maze.h"

static int	set_count(int orig_count, int new_count)
{
	if (orig_count < new_count)
		return (new_count);
	return (orig_count);
}

static int	traverse_path(char map[140][142], int prev_x, int prev_y, int cur_x, int cur_y)
{
	int	count;

	count = 0;
	if (map[cur_y][cur_x] == 'S')
		return (1);
	else
		count++;
	if ((prev_x < cur_x && map[cur_y][cur_x] == '7') || (prev_x > cur_x && map[cur_y][cur_x] == 'F'))
		return (count += traverse_path(map, cur_x, cur_y, cur_x, cur_y + 1));
	else if ((prev_x < cur_x && map[cur_y][cur_x] == 'J') || (prev_x > cur_x && map[cur_y][cur_x] == 'L'))
		return (count += traverse_path(map, cur_x, cur_y, cur_x, cur_y - 1));
	else if (prev_x < cur_x && map[cur_y][cur_x] == '-')
		return (count += traverse_path(map, cur_x, cur_y, cur_x + 1, cur_y));
	else if (prev_x > cur_x && map[cur_y][cur_x] == '-')
		return (count += traverse_path(map, cur_x, cur_y, cur_x - 1, cur_y));
	else if ((prev_y < cur_y && map[cur_y][cur_x] == 'L') || (prev_y > cur_y && map[cur_y][cur_x] == 'F'))
		return (count += traverse_path(map, cur_x, cur_y, cur_x + 1, cur_y));
	else if ((prev_y < cur_y && map[cur_y][cur_x] == 'J') || (prev_y > cur_y && map[cur_y][cur_x] == '7'))
		return (count += traverse_path(map, cur_x, cur_y, cur_x - 1, cur_y));
	else if (prev_y < cur_y && map[cur_y][cur_x] == '|')
		return (count += traverse_path(map, cur_x, cur_y, cur_x, cur_y + 1));
	else if (prev_y > cur_y && map[cur_y][cur_x] == '|')
		return (count += traverse_path(map, cur_x, cur_y, cur_x, cur_y - 1));
	return (count);
}

static int	start_path(char map[140][142], int start_x, int start_y)
{
	int	count;
	int	dir;

	dir = 0;
	count = 0;
	while (dir < 4)
	{
		if (dir == 0) //North
		{
			if ((map[start_y - 1][start_x] == '|') || (map[start_y - 1][start_x] == 'F') || (map[start_y - 1][start_x] == '7'))
				count = set_count(count, traverse_path(map, start_x, start_y, start_x, start_y - 1));
		}
		else if (dir == 1) //East
		{
			if ((map[start_y][start_x + 1] == '-') || (map[start_y][start_x + 1] == 'J') || (map[start_y][start_x + 1] == '7'))
				count = set_count(count, traverse_path(map, start_x, start_y, start_x + 1, start_y));
		}
		else if (dir == 2) //South
		{
			if ((map[start_y + 1][start_x] == '|') || (map[start_y + 1][start_x] == 'J') || (map[start_y + 1][start_x] == 'L'))
				count = set_count(count, traverse_path(map, start_x, start_y, start_x, start_y + 1));
		}
		else //West
		{
			if ((map[start_y][start_x - 1] == '-') || (map[start_y][start_x - 1] == 'L') || (map[start_y][start_x - 1] == 'F'))
				count = set_count(count, traverse_path(map, start_x, start_y, start_x - 1, start_y));
		}
		dir++;
	}
	return (count);
}

void	check_maze(char map[140][142])
{
	int	x;
	int	y;
	int	steps;

	y = 0;
	steps = 0;
	while (y < 140)
	{
		x = 0;
		while (x < 142)
		{
			if (map[y][x] == 'S')
				steps = start_path(map, x, y);
			x++;
		}
		y++;
	}
	if (steps == 0)
		ft_prn_error(2);
	else
		printf("Number of steps: %d\nFurthest point: %d steps\n", steps, steps / 2);
}
