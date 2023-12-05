/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:58:28 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/03 16:58:16 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gears.h"

void	parse_values(int fd)
{
	char	**input;
	int		result;
	int		i;

	i = 0;
	result = 0;
	input = malloc(sizeof(char *) * 140);
	if (input == NULL)
		exit(1);
	while (i < 140)
	{
		input[i] = malloc(sizeof(char) * 141 + 1);
		if (input[i] == NULL)
			exit(1);
		result = read(fd, input[i], 141);
		i++;
	}
	result = find_value(input);
	ft_print_num(result);
}
