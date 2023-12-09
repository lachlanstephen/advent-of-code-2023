/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:17:52 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/01 18:24:54 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calibration.h"

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
	while (line[++i] != 0)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			nums += line[i] - '0';
			nums *= 10;
			break ;
		}
	}
	while (--length >= 0)
	{
		if (line[length] >= '0' && line[length] <= '9')
		{
			nums += line[length] - '0';
			break ;
		}
	}
	return (nums);
}

void	parse_values(int fd)
{
	char		temp;
	int			count;
	static char	line[10000];
	int			result;

	count = 0;
	result = 0;
	while ((read(fd, &temp, 1) != 0))
	{
		if (temp == '\n')
		{
			line[count] = '\0';
			result += find_value(line);
			count = 0;
		}
		else
		{
			line[count] = temp;
			count++;
		}
	}
	ft_print_num(result);
	ft_putchar('\n');
}
