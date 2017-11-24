/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:14:17 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/24 11:49:37 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

void	ft_prtabt(t_t *tab)
{
	while (tab->map)
	{
		printf("%d\n", tab->map);
		tab++;
	}
}

t_t		ft_parseone(char *s)
{
	t_t		out;
	int		i;

	i = 0;
	out.map = 0;
	while (i < 21 && s[i])
	{
		if (s[i] == '#')
			out.map = out.map | 1 << (i - (i + 1) / 5);
		i++;
	}
	while (((out.map & 4369) ^ 4369) == 4369)
		out.map = out.map >> 1;
	while (((out.map & 15) ^ 15) == 15)
		out.map = out.map >> 4;
	return (out);
}

t_t		*ft_parse(char *s)
{
	int		t_count;
	int		i;
	t_t		*out;

	t_count = (ft_strlen(s) + 1) / 21;
	if (!(out = (t_t*)malloc(sizeof(t_t) * (t_count + 1))))
		return (NULL);
	i = 0;
	while (i < t_count)
	{
		out[i] = ft_parseone(s + i * 21);
		i++;
	}
	out[i].map = 0;
	ft_prtabt(out);
	return (out);
}
