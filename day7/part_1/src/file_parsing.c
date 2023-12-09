/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:58:28 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 19:02:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camel_cards.h"

static bool	valid_card(char c)
{
	char	val_cards[13] = "AKQJT98765432";
	int		i;

	i = -1;
	while (++i < 13)
	{
		if (c == val_cards[i])
			return (true);
	}
	return (false);
}



void	parse_values(int fd, int lines, t_hands *hand, int i)
{
	int			j;
	char		temp;
	char		bids[16];

	while (++i < lines)
	{
		j = 0;
		while (read(fd, &temp, 1) != 0)
		{
			if (temp == '\n')
			{
				bids[j - 6] = '\0';
				break ;
			}
			if (j == 5 && temp == ' ')
				hand[i].cards[j] = '\0';
			else if (j == 5 && temp != ' ')
				ft_prn_error(3);
			else if (j < 5)
			{
				if (valid_card(temp) == false)
					ft_prn_error(3);
				hand[i].cards[j] = temp;
			}
			else
				bids[j - 6] = temp;
			j++;
		}
		if (lines == 1)
			bids[j - 6] = '\0';
		hand[i].bid = ft_positive_atol(bids);
		hand[i].type = ft_calc_type(hand[i].cards);
	}
	ft_compare_hands(hand, lines);
}
