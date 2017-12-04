/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:22:46 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/04 12:25:24 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

static void		ft_endline(int *a, unsigned char size, int *d, unsigned char *i)
{
	(*a) += 16 - size;
	(*d)++;
	(*i)++;
}

static void		ft_endul(int *man, int *dif, int *a)
{
	(*man)++;
	(*a) = 0;
	(*dif) = 0;
}

static char		*ft_display_t(char *out, int a, unsigned char size, t_t *input)
{
	int				bit;
	int				dif;
	unsigned char	i;
	int				man;

	man = 0;
	i = -1;
	dif = 0;
	bit = 0;
	while (bit != 4 && (++a + 1) && (++i + 1))
	{
		if (out[i] == '\n')
			ft_endline(&a, size, &dif, &i);
		if (dif == 4)
			ft_endul(&man, &dif, &a);
		if (ft_bitat(input->map[man], a) == 1)
		{
			out[i] = input->letter;
			bit++;
		}
	}
	return (out);
}

char			*ft_display(t_t *input, unsigned char size)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = (char*)malloc((size * size + size))))
		return (NULL);
	ft_memset(out, '.', size * size + size);
	while (i != (size * size + size))
	{
		if ((i + 1) % (size + 1) == 0 && i != 0)
			out[i] = '\n';
		i++;
	}
	out[i] = '\0';
	while (input->letter != 0)
	{
		ft_display_t(out, -1, size, input);
		input++;
	}
	ft_putstr(out);
	return (out);
}
