/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:00:37 by kdouveno          #+#    #+#             */
/*   Updated: 2017/12/01 16:00:39 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

void	ft_prtest(unsigned long map[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_prtabt(map[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_prtabt(unsigned long map)
{
	int i;

	i = 0;
	while (i < 64)
	{
		if (i % 16 == 0)
			ft_putchar('\n');
		ft_putchar(ft_bitat(map, i) + 48);
		i++;
	}
}
