/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:56:36 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/10 22:11:55 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_maze.h"

void	ft_prn_error(int num)
{
	if (num == 0)
		write(2, "Wrong argument amount!\n", 23);
	else if (num == 1)
		write(2, "File Error!\n", 12);
	else if (num == 2)
		write(2, "Input Error: No start location specified\n", 41);
	else
		write(2, "Error!\n", 7);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	map[140][142];

	if (argc != 2)
		ft_prn_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || (read(fd, NULL, 0) == -1))
		ft_prn_error(1);
	parse_values(fd, map);
	close(fd);
	return (0);
}
