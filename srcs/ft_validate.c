/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:40:52 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/30 14:10:49 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

int		ft_validate(t_t *tetros)
{
	int		pos;
	int		links;

	while (tetros->letter)
	{
		pos = 0;
		links = 0;
		while (pos != 64)
		{
			if (ft_bitat(tetros->map[0], pos) == 1)
				links = links + ft_count_link(tetros->map[0], pos);
			pos++;
		}
		if (links != 6 && links != 8)
			return (1);
		tetros++;
	}
	return (0);
}
