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

int		ft_mapadd(t_map map, t_map mask)
{
	int i;

	i = 0;
	while (i < 3)
		map[i++] |= mask;
}

int		ft_mapdiff(t_map map, t_map mask)
{
	int i;

	i = 0;
	while (i < 3)
		map[i++] &= ~mask;
}

int		ft_collapse(unsigned long test[4], unsigned long try[4])
{
	int i;

	i = 0;
	while (!(test[i] & try[i]) && i < 4)
		i++;
	if (i == 3)
		return (0);
	return (1);
}

int		ft_place(t_t *tetros, t_map trymap, unsigned char size)
{

	return (0);
}

void ft_initmaps(t_map try, t_map x, t_map y, unsigned char size)
{
	int i;

	ft_bzero(try, 32);
	ft_bzero(x, 32);
	ft_bzero(y, 32);
	i = 0;
	size = 6;
	while (i < 4)
	{
		x[i] = 0x1000100010001 << size;
		if (size / 4 == i)
		{
			y[i] = 0xFFFF << (size % 4 * 16);
		}
		i++;
	}

}

void	ft_shiftx(t_map map, char shift)
{
	int i;

	i = 0;
	if (shift < 0)
		while (i < 4)
			map[i++] <<= -shift;
	else
		while (i < 4)
		 	map[i++] <<= shift;

}

void	ft_shifty(t_map map, char shift)
{
	int i;

	i = 3;
	if (shift < 0)
		while (i >= 0)
			map[i--] <<= -shift * 16;
	else
		while (i >= 0)
			map[i--] <<= shift * 16;
}

int		ft_resolve(t_t *tetros,  unsigned char size)
{
	t_map trymap;
	t_map xlimit;
	t_map ylimit;
	int x;
	int y;

	if (!tetros->letter)
		return (0);
	x = 0;
	y = 0;
	ft_initmaps(trymap, xlimit, ylimit, size);
	while (ft_collapse(tetros->map, ylimit))
	{
		if (ft_collapse(tetros->map, trymap))
		{
			ft_shiftx(tetros->map, 1);
			ft_prtest(tetros->map);
			x++;
			continue ;
		}
		if (ft_collapse(tetros->map, xlimit))
		{
			printf("ca passe\n");
			ft_shiftx(tetros->map, -x);
			x = 0;
			ft_shifty(tetros->map, 1);
			continue ;
		}
		ft_mapadd()
		if (!ft_resolve(tetros + 1, size))
			return (0);
	}
	ft_shifty(tetros->map, -y);
	return (1);
}
