/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:06:24 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/03 17:11:05 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gears.h"


	if ((input[y][x] > ' ' && input[y][x] < '0' && input[y][x] != '.')
		|| (input[y][x] == '@')
		|| (input[y][x] >= '[' && input[y][x] <= '`')
		|| (input[y][x] >= '{' && input[y][x] <= '~'))
		check_symbol(input, x, y);