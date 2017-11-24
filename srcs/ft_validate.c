#include "../hds/main.h"

int		ft_validate(t_t *tetros)
{
	unsigned char	i;
	unsigned char	last;
	
	i = 0;
	last = -1;
	while (tetros->map)
	{
		while (tetros->map / 2)
		{
			if (tetros->map % 2)
			{
				if (last >= 0 && i - last != 1 && i - last != 4)
					return (1);
				last = i;
			}
			i++;
		}
	}
	return (0);
}
