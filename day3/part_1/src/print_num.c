/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:07:19 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/03 16:07:20 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gears.h"

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
