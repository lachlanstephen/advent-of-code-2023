/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:17:52 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/01 19:27:50 by lstephen         ###   ########.fr       */
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

int	check_written(char *line, int i, int backwards)
{
	char	*valid_digs[] = {"one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};
	int		j;
	int		temp;
	int		dig_len;

	j = 0;
	temp = i;
	if (backwards == 0)
	{
		while (j <= 8)
		{
			i = temp;
			while (line[i] == valid_digs[j][i])
			{
				if (valid_digs[j][i + 1] == '\0')
					return (j + 1);
				i++;
			}
			j++;
		}
	}
	else
	{
		while (j <= 8)
		{
			i = temp;
			dig_len = ft_strlen(valid_digs[j]) - 1;
			while (line[i] == valid_digs[j][dig_len])
			{
				if (dig_len == 0)
					return (j + 1);
				i--;
				dig_len--;
			}
			j++;
		}
	}
	return (0);
}

int	check_digit(char c)
{
	int	nums;

	nums = 0;
	if (c >= '0' && c <= '9')
	{
		nums += c - '0';
		nums *= 10;
	}
	return (nums);
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
		if (check_written(&line[i], 0, 0) != 0)
		{
			nums += check_written(&line[i], 0, 0);
			nums *= 10;
			break ;
		}
		if (check_digit(line[i]) != 0)
		{
			nums += check_digit(line[i]);
			break ;
		}
	}
	while (--length >= 0)
	{
		if (check_written(line, length, 1) != 0)
		{
			nums += check_written(line, length, 1);
			break ;
		}
		if (check_digit(line[length]) != 0)
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
