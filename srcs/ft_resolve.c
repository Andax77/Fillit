#include "libft.h"

int		ft_collapse(t_t t1, t_t t2, x, y)
{
	if (x < 0)
	{
		t1.map
	}
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
		difx = tmp.x - tetros->x;
		dify = tmp.y - tetros->y;
		if ((!difx && !dify) || (difx >= 4 && dify >= 4))
			return (1);

	}
}

t_t		*ft_resolve(t_t *tetros)
{
	if (ft_iscollapsing(tetros))
	{
		tetros->
	}
}
