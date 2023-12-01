/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:12:21 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/01 18:22:56 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calibration.h"

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Wrong argument amount!\n", 23);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || (read(fd, NULL, 0) == -1))
	{
		write(2, "File Error!\n", 11);
		exit(1);
	}
	parse_values(fd);
	close(fd);
	return (0);
}
