/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:58:28 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/07 18:18:43 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camel_cards.h"

void	parse_values(int fd)
{
	t_hand[1000];
	int			result;
	int			i;
	char		temp;
	static char	str;

	i = 0;
	result = 0;
	while (i < 1000)
	{
		while (read(fd, &temp, 1) != 0)
		{
			if (temp == '\n')
				break ;
		}
		t_hand[i].bid = i;
		i++;
	}
	result = find_value(input);
	ft_print_num(result);
}
