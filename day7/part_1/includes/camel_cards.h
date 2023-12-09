/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_cards.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:43:53 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 18:52:57 by darkwater        ###   ########.fr       */
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
	char	cards[6];
	long	bid;
	int		type;
}			t_hands;

int			ft_calc_type(char *cards);

long		ft_positive_atol(char *str);

void		parse_values(int fd, int lines, t_hands *hand, int i);
void		ft_putchar(char c);
void		ft_print_num(int result);
void		ft_prn_error(int errnum);
void		ft_compare_hands(t_hands *hand, int lines);

void		*ft_memset(void *s, int c, size_t n);

#endif
