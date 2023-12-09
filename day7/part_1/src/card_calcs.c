/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card_calcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:47 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 18:29:08 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camel_cards.h"

static int	ft_type_val(int	*card_count)
{
	int	i;
	int	dup1;
	int	dup2;
	int	count;

	i = -1;
	dup1 = 0;
	dup2 = 0;
	count = 5;
	while (++i < 13 && count > 0)
	{
		if (card_count[i] > 3)
			dup1 = card_count[i];
		else if (card_count[i] == 2 || card_count[i] == 3)
		{
			if (dup1 == 2 || dup1 == 3)
				dup2 = card_count[i];
			else
				dup1 = card_count[i];
		}
		if (card_count[i] != 0)
			count -= card_count[i];
	}
	if (dup1 >= 4)
		return (++dup1);
	else if (dup1 == 1)
		return (0);
	else if ((dup1 == 2 && dup2 == 3) || (dup1 == 3 && dup2 == 2))
		return (4);
	else if (dup1 == 3)
		return (3);
	else if (dup1 == 2 && dup2 == 2)
		return (2);
	else if (dup1 == 2)
		return (1);
	return (0);
}

int	ft_calc_type(char *cards)
{
	int	card_count[13];
	int	i;

	i = -1;
	ft_memset(card_count, 0, sizeof(card_count));
	while (cards[++i] != 0)
	{
		if (cards[i] == 'A')
			card_count[0]++;
		else if (cards[i] == 'K')
			card_count[1]++;
		else if (cards[i] == 'Q')
			card_count[2]++;
		else if (cards[i] == 'J')
			card_count[3]++;
		else if (cards[i] == 'T')
			card_count[4]++;
		else
			card_count[14 - (cards[i] - '0')]++;
	}
	return (ft_type_val(card_count));
}
