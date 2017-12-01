/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_shifts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:00:59 by kdouveno          #+#    #+#             */
/*   Updated: 2017/12/01 16:01:00 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

void	ft_shiftx(t_map map, char shift)
{
	int i;

	i = 0;
	if (shift < 0)
		while (i < 4)
			map[i++] >>= -shift;
	else
		while (i < 4)
			map[i++] <<= shift;
}

void	ft_shifty_rev(t_map map, char shift)
{
	int i;
	int y;

	y = 0;
	while (y < shift)
	{
		i = 0;
		while (i < 4)
		{
			map[i] >>= 16;
			map[i] |= i == 3 ? 0UL : (map[i + 1] & 0xFFFFUL) << 48;
			i++;
		}
		y++;
	}
}

void	ft_shifty(t_map map, char shift)
{
	int i;
	int y;

	y = 0;
	while (y < shift)
	{
		i = 3;
		while (i >= 0)
		{
			map[i] <<= 16;
			map[i] |= i == 0 ? 0UL : (map[i - 1] & ULLLINE) >> 48;
			i--;
		}
		y++;
	}
}
