/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_comparison.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:32:21 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 18:57:07 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camel_cards.h"

void	ft_compare_hands(t_hands *hand, int lines)
{
	int		count;
	int		multiplier;
	int		type;
	long	score;

	score = 0;
	multiplier = lines;
	type = 6;
	while (multiplier >= 1)
	{
		count = 0;
		while (count < lines)
		{
			if (hand[count].type == type)
			{
				score += hand[count].bid * multiplier;
				multiplier--;
			}
			count++;
		}
		type--;
	}
	printf("The final amount: %lu\n", score);
}
