/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:40:43 by kdouveno          #+#    #+#             */
/*   Updated: 2017/12/01 16:37:22 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_initmaps(t_map x, t_map y, unsigned char size)
{
	int i;

	ft_bzero(x, 32);
	ft_bzero(y, 32);
	i = 0;
	while (i < 4)
	{
		x[i] = 0x1000100010001UL << size;
		if (size / 4 == i)
			y[i] = 0xFFFFUL << (size % 4 * 16);
		i++;
	}
}

static int	ft_limx(int *x, int *y, t_t *tetro, t_map xlimit)
{
	if (ft_collapse(tetro->map, xlimit))
	{
		ft_shiftx(tetro->map, -(*x));
		*x = 0;
		ft_shifty(tetro->map, 1);
		(*y)++;
		return (1);
	}
	return (0);
}

static int	ft_over(int *x, t_t *tetro, t_map trymap)
{
	if (ft_collapse(tetro->map, trymap))
	{
		ft_shiftx(tetro->map, 1);
		(*x)++;
		return (1);
	}
	return (0);
}

static int	ft_bckt(t_t *tetros, int *x, unsigned char size, t_map trymap)
{
	if (ft_resolve(tetros + 1, size))
	{
		ft_mapdiff(trymap, tetros->map);
		ft_shiftx(tetros->map, 1);
		(*x)++;
		return (1);
	}
	return (0);
}

int			ft_resolve(t_t *tetros, unsigned char size)
{
	static t_map	trymap;
	t_map			xlimit;
	t_map			ylimit;
	int				x;
	int				y;

	if (!tetros->letter)
		return (0);
	x = 0;
	y = 0;
	ft_initmaps(xlimit, ylimit, size);
	while (!ft_collapse(tetros->map, ylimit))
	{
		if (ft_limx(&x, &y, tetros, xlimit))
			continue;
		if (ft_over(&x, tetros, trymap))
			continue;
		ft_mapadd(trymap, tetros->map);
		if (!ft_bckt(tetros, &x, size, trymap))
			return (0);
	}
	ft_shifty_rev(tetros->map, y);
	return (1);
}
