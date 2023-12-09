/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:57:30 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 19:00:50 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camel_cards.h"

void	ft_prn_error(int errnum)
{
	if (errnum == 0)
		write(2, "Wrong argument amount!\n", 23);
	else if (errnum == 1)
		write(2, "File Error!\n", 11);
	else if (errnum == 2)
		write(2, "Error allocating memory!\n", 25);
	else if (errnum == 3)
		write(2, "Invalid cards found in hand!\n", 29);
	else
		write(2, "Error!\n", 7);
	exit(1);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	temp;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || (read(fd, NULL, 0) == -1))
		return (-1);
	while (read(fd, &temp, 1) != 0)
	{
		if (temp == '\n')
			count++;
	}
	close(fd);
	if (count == 0)
		count++;
	return (count);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		lines;
	t_hands	*hand;

	if (argc != 2)
		ft_prn_error(0);
	lines = count_lines(argv[1]);
	hand = malloc(sizeof(t_hands) * lines);
	if (hand == NULL)
		ft_prn_error(2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || (read(fd, NULL, 0) == -1) || lines == -1)
		ft_prn_error(1);
	parse_values(fd, lines, hand, -1);
	close(fd);
	return (0);
}
