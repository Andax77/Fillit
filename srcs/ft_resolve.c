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
	printf("avant:\n  t1\n");
	ft_pr_sh(t1.map);
	printf("  t2\n");
	ft_pr_sh(t2.map);
	if (y < 0)
		ft_shifty(&(t1.map), -y);
	else
		ft_shifty(&(t2.map), y);
	if (x < 0)
		ft_shiftx(&(t1.map), -x);
	else
		ft_shiftx(&(t2.map), x);
	printf("apres:\n  t1\n");
	ft_pr_sh(t1.map);
	printf("  t2\n");
	ft_pr_sh(t2.map);
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
	while (tetros->letter != 'A')
	{
		tetros--;
		difx = tmp->x - tetros->x;
		dify = tmp->y - tetros->y;
		if ((!difx && !dify) || (difx >= 4 && dify >= 4))
			return (0);
		if (ft_collapse(*tmp, *tetros, difx, dify))
			return (0);
	}
	return (1);
}

void	ft_copy_result(t_t *tetros, *t_t out)
{
	while (tetros-> != 'A')
	{
		*out = *tetros;
		tetros--;
		out--;
	}
}

void	*ft_resolve(t_t *tetros, int x, int y, t_t *out)
{
	if (!tetros->map)
	{
		if (tetros->x > (tetros->y = ft_find_size(tetros)))
		{
			tetros->x = tetros->y;
			ft_copy_result(tetros, out);
		}
	}
	if (ft_isvalid(tetros))
	{
		ft_resolve(tetros + 1; 0, y + 1, out);
	}
	else
	{
		ft_resolve(tetros; x + 1, y, out);
	}
}

int main(int argc, char const *argv[])
{
	t_t t1;
	t_t t2;

	t1.map = 561;
	t2.map = 116;
	t1.x = 1;
	t2.x = 0;
	t1.y = 0;
	t2.y = 2;
	printf("%d\n", ft_spaced(t1, t2, t2.x - t1.x, t2.y - t1.y));
	return 0;
}
