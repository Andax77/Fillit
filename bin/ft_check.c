/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:26:40 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/23 15:23:10 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_checkchar(char *c, int *i, char *t_count, char *hashs)
{
	if (*t_count > 26)
		return (1);
	if ((*i - *t_count + 1) % 5 == 0)
	{
		if (c[*i] != '\n')
			return (1);
		else if ((c[*i + 1] == '\n' && (*i + 2) % 21 == 0) || !(c[*i + 1]))
		{
			if (*hashs != 4)
				return (1);
			*hashs = 0;
			(*t_count)++;
			*i += c[*i + 1] ? 1 : 0;
		}
	}
	else
	{
		if (c[*i] != '.' && c[*i] != '#')
			return (1);
		else if (c[*i] == '#')
			(*hashs)++;
	}
	return (0);
}

int				ft_check(char *c)
{
	int			i;
	char		t_count;
	char		hashs;
	size_t		len;
	int			error;

	len = ft_strlen(c);
	if ((len + 1) % 21 != 0 || len + 1 > 21 * 26)
		return (1);
	i = 0;
	t_count = 0;
	hashs = 0;
	while (c[i])
	{
		error = ft_checkchar(c, &i, &t_count, &hashs);
		if (error)
			return (1);
		i++;
	}
	return (0);
}
