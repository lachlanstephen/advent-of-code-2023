/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_cards.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:43:53 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/07 18:00:03 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMEL_CARDS_H
# define CAMEL_CARDS_H

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
