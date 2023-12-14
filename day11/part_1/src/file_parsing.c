/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:52 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/14 23:51:25 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosmic_expansion.h"

static void	ft_arg_printing(char **init_gal, char **exp_gal, int *count)
{
	int	y;

	y = -1;
	printf("Old row amount: %d, Old column amount: %d\n\nOld Galaxy:\n",
		ROW_AMOUNT, ROW_WIDTH);
	while (++y < ROW_AMOUNT)
		printf("%s\n", init_gal[y]);
	y = -1;
	printf("\nNew row amount: %d, New column amount: %d\n\nNew Galaxy:\n",
		count[0], count[1]);
	while (++y < count[0])
		printf("%s\n", exp_gal[y]);
}

void	parse_values(int fd)
{
	int		i;
	int		count[2];
	char	**init_gal;
	char	**expanded_gal;

	i = -1;
	init_gal = malloc(sizeof(char *) * (ROW_AMOUNT));
	if (init_gal == NULL)
		ft_prn_error(2);
	while (++i < ROW_AMOUNT)
	{
		init_gal[i] = malloc(sizeof(char) * (ROW_WIDTH));
		if (init_gal[i] == NULL)
			ft_free_error(init_gal, i);
	}
	i = -1;
	while (read(fd, init_gal[++i], ROW_WIDTH) != 0)
		init_gal[i][ROW_WIDTH - 1] = '\0';
	expanded_gal = galaxy_expansion(init_gal, count);
	ft_arg_printing(init_gal, expanded_gal, count);
	total_gal_distance(expanded_gal, count);
}
