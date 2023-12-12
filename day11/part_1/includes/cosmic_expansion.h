/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosmic_expansion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:57:54 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/13 05:28:57 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSMIC_EXPANSION_H
# define COSMIC_EXPANSION_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef ROW_AMOUNT
#  define ROW_AMOUNT 140
# endif

# ifndef ROW_WIDTH
#  define ROW_WIDTH 141
# endif

char		**galaxy_expansion(char **init_gal, int *count);

void		ft_prn_error(int num);
void		parse_values(int fd);
void		ft_free_error(char **gal, int i);
void		total_gal_distance(char **exp_gal, int *count);

#endif
