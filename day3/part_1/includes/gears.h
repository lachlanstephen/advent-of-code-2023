/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gears.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:56:49 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/03 16:37:35 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEARS_H
# define GEARS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

int		find_value(char **input);

void	parse_values(int fd);
void	ft_putchar(char c);
void	ft_print_num(int result);

#endif
