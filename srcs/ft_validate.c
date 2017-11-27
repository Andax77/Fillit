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
	int		t_link;

	while (tetros->map)
	{
		pos = 0;
		t_link = 0;
		while (pos != 16)
		{
			if (ft_state_bit(tetros->map, pos) == 1)
				t_link = t_link + ft_count_link(tetros->map, pos);
			pos++;
		}
		if (t_link != 6 && t_link != 8)
			return (1);
		tetros++;
	}
	return (0);
}
