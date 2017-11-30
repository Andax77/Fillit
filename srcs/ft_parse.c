/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:14:17 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/29 14:25:08 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

char	ft_bitat(unsigned long src, unsigned char pos)
{
	return (src >> pos & 1);
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

void	ft_find_dims(t_t *out)
{
int i;
	unsigned long mask;

	mask = 0xF0000;
	i = 1;
	while ((out->map & mask) != 0)
	{
		mask <<= 16;
		i++;
	}
	out->dy = i;
	if (i == 2 && ((out->map & 68) == 0))
		out->dx = i;
	else
		out->dx = 5 - i;
}

t_t		ft_parseone(char *s)
{
	t_t				out;
	int				i;
	unsigned long	mask;

	i = 0;
	out.map = 0;
	while (i < 21 && s[i])
	{
		if (s[i] == '#')
			out.map = out.map | (1LU << (((unsigned long)i + 1LU) / 5LU
				* 16LU + (unsigned long)i % 5LU));
		i++;
	}
	mask = 0x1000100010001;
	while (!(out.map & mask))
		out.map = out.map >> 1;
	while (!(out.map & 0xF))
		out.map = out.map >> 16;
	out.x = 0;
	out.y = 0;
	ft_find_dims(&out);
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
	out[i].map = 0;
	return (out);
}
