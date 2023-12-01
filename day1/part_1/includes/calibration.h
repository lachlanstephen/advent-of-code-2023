/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:10:07 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/01 18:14:02 by lstephen         ###   ########.fr       */
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
