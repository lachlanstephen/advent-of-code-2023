/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:49:58 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/01 18:14:00 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calibration.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_num(int result)
{
	if (result >= 10)
		ft_print_num(result / 10);
	ft_putchar(result % 10 + '0');
}
