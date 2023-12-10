/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasteland.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:03:31 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 13:04:01 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WASTELAND_H
# define WASTELAND_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct hands
{
	char	cards[5];
	int		bid;
	int		type;
}			t_hand;

int		find_value(char **input);

void	parse_values(int fd);
void	ft_putchar(char c);
void	ft_print_num(int result);

#endif
