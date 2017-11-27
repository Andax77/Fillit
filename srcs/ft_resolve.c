#include "../hds/main.h"
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_pr_sh(unsigned short x)
{
	int i;

	if (x == 0)
		ft_putchar('x');
	i = 0;
	while (x)
	{
		ft_putchar(x % 2 + 48);
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		x /= 2;
		i++;
	}
	while (i < 16)
	{
		ft_putchar('0');
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	ft_shiftx(unsigned short *target, int x)
{
	unsigned short tmp;

	tmp = 61166;
	while (x > 0)
	{
		*target <<= 1;
		*target &= tmp;
		x--;
	}
	
}

void	ft_shifty(unsigned short *target, int y)
{
	*target <<= y * 4;
}

int		ft_collapse(t_t t1, t_t t2, int	x, int y)
{
	if (y < 0)
		ft_shifty(&(t1.map), -y);
	else
		ft_shifty(&(t2.map), y);
	if (x < 0)
		ft_shiftx(&(t1.map), -x);
	else
		ft_shiftx(&(t2.map), x);
	if ((t1.map ^ t2.map) != (t1.map | t2.map))
		return (1);
	return (0);
}

int		ft_isvalid(t_t *tetros)
{
	t_t		*tmp;
	int		difx;
	int		dify;

	tmp = tetros;
	tetros--;
	while ((tetros + 1)->letter != 'A')
	{
		difx = tmp->x - tetros->x;
		dify = tmp->y - tetros->y;
		printf("prout: l: %c\n", tetros->letter);
		if ((!difx && !dify) || (difx >= 4 && dify >= 4))
			return (0);
		if (ft_collapse(*tmp, *tetros, difx, dify))
			return (0);
		tetros--;
	}
	return (1);
}

void	ft_copy_result(t_t *tetros, t_t *out)
{
	while ((tetros + 1)->letter != 'A')
	{
		*out = *tetros;
		tetros--;
		out--;
	}
}

int		ft_find_size(t_t *tetros)
{
	int i;

	i = 0;
	while ((tetros + 1)->letter != 'A')
	{
		if (tetros->x + tetros->dx > i)
			i = tetros->x + tetros->dx;
		if (tetros->y + tetros->dy > i)
			i = tetros->y + tetros->dy;
		tetros--;
	}
	return i;
}

int		ft_resolve(t_t *tetros, t_t *out, unsigned char size)
{
	if (tetros->map == 0)
	{
		ft_copy_result(tetros, out);
		return (1);
	}
	tetros->x = 0;
	tetros->y = 0;
	while (tetros->y + tetros->dy <= size)
	{
		printf("map: %d, l: %d, x: %d, y: %d, dx: %d, dy: %d, size: %d\n", tetros->map, tetros->letter, tetros->x, tetros->y, tetros->dx, tetros->dy, size);
		if (tetros->x + tetros->dx > size)
		{
			tetros->x = 0;
			tetros->y++;
			continue ;
		}
		printf("%d\n", ft_isvalid(tetros));
		if (size == 4 && tetros->letter == 'B' && tetros->x == 2)
			return (1);
		if (ft_isvalid(tetros))
		{
			ft_resolve(tetros + 1, out, size);
			tetros->x++;
		}

		tetros->x++;
	}
	return (0);
}

/*int main(int argc, char const *argv[])
{
	t_t t1;
	t_t t2;

	t1.map = 561;
	t2.map = 116;
	t1.x = 1;
	t2.x = 0;
	t1.y = 0;
	t2.y = 2;
	printf("%d\n", ft_collapse(t1, t2, t2.x - t1.x, t2.y - t1.y));
	return 0;
}*/
