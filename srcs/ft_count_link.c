/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:59:41 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/27 18:34:25 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

int			ft_count_link(int map, int pos)
{
	int		link;

	link = 0;
	if (ft_state_bit(map, pos + 1) == 1)
		link++;
	if (ft_state_bit(map, pos - 1) == 1)
		link++;
	if (ft_state_bit(map, pos + 4) == 1)
		link++;
	if (ft_state_bit(map, pos - 4) == 1)
		link++;
	return (link);
}
