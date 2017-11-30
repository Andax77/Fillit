/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:40:52 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/27 18:34:28 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

int		ft_validate(t_t *tetros)
{
	int		pos;
	int		links;

	while (tetros->map)
	{
		pos = 0;
		links = 0;
		while (pos != 64)
		{
			if (ft_bitat(tetros->map, pos) == 1)
				links = links + ft_count_link(tetros->map, pos);
			pos++;
		}
		if (links != 6 && links != 8)
			return (1);
		tetros++;
	}
	return (0);
}
