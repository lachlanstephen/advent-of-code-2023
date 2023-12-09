/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:09:51 by darkwater         #+#    #+#             */
/*   Updated: 2023/12/09 18:28:43 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camel_cards.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char *)s)[i] = c;
	return (s);
}

char	*ft_strtrim(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			str[i] = '\0';
			break ;
		}
	}
	return (str);
}

long	ft_positive_atol(char *str)
{
	int		i;
	long	result;

	i = -1;
	result = 0;
	str = ft_strtrim(str);
	while (str[++i] != 0)
	{
		result *= 10;
		result += str[i] - '0';
	}
	return (result);
}
