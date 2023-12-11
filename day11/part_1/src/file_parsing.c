/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:52 by lstephen          #+#    #+#             */
/*   Updated: 2023/12/11 17:20:36 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cosmic_expansion.h"

void	parse_values(int fd, char init_gal[140][142])
{
	int		i;
	char	**expanded_gal;

	i = 0;
	while (read(fd, &init_gal[i], 141) != 0)
	{
		init_gal[i][141] = '\0';
		i++;
	}
	expanded_gal = galaxy_expansion(init_gal);
}
