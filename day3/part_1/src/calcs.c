/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:26:49 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/03 17:31:55 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gears.h"

void	check_symbol(char **input, int x, int y)
{
	printf("Symbol: %c Pos: %d, %d\n", input[y][x], y, x);
}

//int	nums[4] = { x, y, result, count, start }
int	find_value(char **input)
{
	int		nums[4];
	static char	cur[10];
	bool	not_zero;

	nums[1] = -1;
	nums[2] = -1;
	nums[3] = 0;
	while (++(nums[1]) < 140)
	{
		nums[0] = -1;
		while (input[nums[1]][++(nums[0])] != 0)
		{
			if (input[nums[1]][nums[0]] >= '0' && input[nums[1]][nums[0]] <= '9')
			{
				cur[(nums[3])] = input[nums[1]][nums[0]];
				(nums[3])++;
				not_zero = true;
			}
			else if (not_zero == true)
			{
				printf("%s\n", cur);
				not_zero = false;
				while (++(nums[2]) <= 9)
					cur[nums[2]] = '\0';
				nums[2] = 0;
				nums[3] = 0;
			}

		}
	}
	return (nums[2]);
}
