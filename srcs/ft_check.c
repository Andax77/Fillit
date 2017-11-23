/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:26:40 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/23 10:10:54 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/check.h"

static void		ft_checkchar(char *c, int *i, char *t_count, char *hashs)
{
		if (*t_count == 27)
			return ;
		if ((*i - *t_count + 1) % 5 == 0)
		{
			if (c[*i] != '\n')
				return ;
			else if (((c[*i + 1] == '\n' && (*i + 2) % 21 == 0)) || !c[*i + 1])
			{
				if (*hashs != 4)
					return ;
				*hashs = 0;
				(*t_count)++;
				(*i)++;
			}
		}
		else
		{
			if (c[*i] != '.' && c[*i] != '#')
				return ;
			else if (c[*i] == '#')
				hashs++;
		}
}

int				ft_check(char *c)
{
	int		i;
	char	t_count;
	char	hashs;
	size_t	len;

	len = ft_strlen(c);
	if ((len + 1) % 21 != 0)
		return (0);
	i = 0;
	t_count = 0;
	hashs = 0;
	while (c[i])
	{
		ft_checkchar(c, &i, &t_count, &hashs);
		i++;
	}
	return (1);
}
