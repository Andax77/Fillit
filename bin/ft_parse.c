/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:14:17 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/30 14:04:07 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_t		ft_parseone(char *s)
{
	t_t				out;
	int				i;
	unsigned long	mask;

	i = 0;
	ft_bzero(out.map, 32);
	while (i < 21 && s[i])
	{
		if (s[i] == '#')
			out.map[0] |= (1LU << (((unsigned long)i + 1LU) / 5LU
				* 16LU + (unsigned long)i % 5LU));
		i++;
	}
	mask = 0x1000100010001;
	while (!(out.map[0] & mask))
		out.map[0] >>= 1;
	while (!(out.map[0] & 0xF))
		out.map[0] >>= 16;
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
		out[i].letter = i + 65;
		i++;
	}
	out[i].letter = 0;
	return (out);
}
