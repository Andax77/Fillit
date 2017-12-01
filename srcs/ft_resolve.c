#include "../hds/main.h"
#include <stdio.h>

void ft_prtest(unsigned long map[4]) {
	int i;

	i = 0;
	while (i < 4)
	{
		ft_prtabt(map[i]);
		i++;
	}
	ft_putchar('\n');
}

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

void ft_initmaps(t_map x, t_map y, unsigned char size)
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

void	ft_shifty(t_map map, char shift)
{
	int i;
	int y;

	y = 0;
	if (shift < 0)
		while (y < -shift)
		{
			i = 0;
			while (i < 4)
			{
				map[i] >>= 16;
				if (i != 3)
					map[i] |= (map[i + 1] & 0xFFFFUL) << 48;
				i++;
			}
			y++;
		}
	else
		while (y < shift)
		{
			i = 3;
			while (i >= 0)
			{
				map[i] <<= 16;
				if (i != 0)
					map[i] |= (map[i - 1] & 0xFFFF000000000000UL) >> 48;
				i--;
			}
			y++;
		}
}

int		ft_place(t_t *tetros, unsigned char size, int *x, int *y)
{
	if (ft_collapse(tetros->map, xlimit))
	{
		ft_shiftx(tetros->map, -(*x));
		*x = 0;
		ft_shifty(tetros->map, 1);
		continue ;
	}
	if (ft_collapse(tetros->map, trymap))
	{
		ft_shiftx(tetros->map, 1);
		(*x)++;
		continue ;
	}
	ft_mapadd(trymap, tetros->map);
	if (ft_resolve(tetros + 1, size))
	{
		ft_mapdiff(trymap, tetros->map);
		ft_shiftx(tetros->map, 1);
		(*x)++;
	}
	else
		return (0);
	(*y)++;
}

int		ft_resolve(t_t *tetros,  unsigned char size)
{
	static t_map trymap;
	t_map xlimit;
	t_map ylimit;
	int x;
	int y;

	if (!tetros->letter)
		return (0);
	x = 0;
	y = 0;
	ft_initmaps(xlimit, ylimit, size);
	while (!ft_collapse(tetros->map, ylimit))
	{
		if (!ft_place(tetros, size, &x, &y)){
			ft_prtest(trymap);
			return (0);
		}
	}
	ft_shifty(tetros->map, -y);
	return (1);
}
