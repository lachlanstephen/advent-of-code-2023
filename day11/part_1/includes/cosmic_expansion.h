/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosmic_expansion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:57:54 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/11 16:11:50 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSMIC_EXPANSION_H
# define COSMIC_EXPANSION_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

void		ft_prn_error(int num);
void		parse_values(int fd, char init_gal[140][142]);

#endif
