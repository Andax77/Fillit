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
}

void	ft_incrmap(unsigned long **map, unsigned char limit)
{
	int i;

	i = 0;
	while (!((0x1000100010001 << (limit - 1)) & map[0][i]))
		i++;
	if (i != 4)
	{
		while (i > 0)
		{
			map[0][i] <<= 16;
			map[0][1] |= (map[0][i - 1] & 0xFFFF000000000000) >> 48;
		}
		map[0][0] <<= 16;
		return ;
	}
	while (i < 4)
	{
		map <<= 1;
		i++;
	}
}

int		ft_collapse(unsigned long test[4], unsigned long try[4])
{
	int i;

	i = 0;
	while (!(test[i] & try[i]))
		i++;
	if (i == 3)
		return (0);
	return (1);
}

int		ft_place(t_t *tetros, unsigned long trymap[4], unsigned char size)
{
	unsigned long testmap[4];

	testmap[0] = tetros->map;
	while (ft_collapse(testmap, trymap))
		ft_incrmap(&testmap, limit);
	return (1);
}

int		ft_resolve(t_t *tetros,  unsigned char size)
{
	static unsigned long trymap[4];

	while (tetros->map){
		if (!tetros->map)
			return (0);
		if (ft_place(tetros, trymap))
			tetros++;
	}
	return (1);
}
