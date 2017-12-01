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

#include "main.h"

char	ft_count_link(unsigned long map, int pos)
{
	int		link;

	link = 0;
	if (ft_bitat(map, pos + 1) == 1)
		link++;
	if (ft_bitat(map, pos - 1) == 1)
		link++;
	if (ft_bitat(map, pos + 16) == 1)
		link++;
	if (ft_bitat(map, pos - 16) == 1)
		link++;
	return (link);
}
