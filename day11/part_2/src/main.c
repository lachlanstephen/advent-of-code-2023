/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:59:20 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/13 05:52:11 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosmic_expansion.h"

void	ft_free_error(char **gal, int i, bool err)
{
	int	j;

	j = -1;
	while (++j < i)
		free(gal[j]);
	free(gal);
	if (err == true)
		ft_prn_error(2);
}

void	ft_prn_error(int num)
{
	if (num == 0)
		write(2, "Wrong argument amount!\n", 23);
	else if (num == 1)
		write(2, "File Error!\n", 12);
	else if (num == 2)
		write(2, "Error allocating memory!\n", 25);
	else
		write(2, "Error!\n", 7);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc != 2)
		ft_prn_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || (read(fd, NULL, 0) == -1))
		ft_prn_error(1);
	parse_values(fd);
	return (0);
}
