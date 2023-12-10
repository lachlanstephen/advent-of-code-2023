/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_maze.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:53:45 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/10 21:42:05 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_MAZE_H
# define PIPE_MAZE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

void		ft_prn_error(int num);
void		parse_values(int fd, char map[140][142]);
void		check_maze(char map[140][142]);

#endif
