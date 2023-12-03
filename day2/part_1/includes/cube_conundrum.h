/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_conundrum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 03:11:57 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/03 03:12:05 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALIBRATION_H
# define CALIBRATION_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

void	parse_values(int fd);
void	ft_putchar(char c);
void	ft_print_num(int result);

#endif
