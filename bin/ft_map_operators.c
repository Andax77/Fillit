/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:00:54 by kdouveno          #+#    #+#             */
/*   Updated: 2017/12/01 16:00:55 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_mapadd(t_map map, t_map mask)
{
	int i;

	i = 0;
	while (i < 3)
	{
		map[i] |= mask[i];
		i++;
	}
}

void	ft_mapdiff(t_map map, t_map mask)
{
	int i;

	i = 0;
	while (i < 3)
	{
		map[i] &= ~mask[i];
		i++;
	}
}

int		ft_collapse(t_map test, t_map try)
{
	int i;

	i = 0;
	while (!(test[i] & try[i]) && i < 4)
		i++;
	if (i == 4)
		return (0);
	return (1);
}

char	ft_bitat(unsigned long src, unsigned char pos)
{
	return (src >> pos & 1);
}
