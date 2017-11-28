/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:22:46 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/28 11:58:47 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"
#include "../hds/libft.h"

void			ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char			*ft_display_t(char *out, int x, int i, t_t *input)
{
	int		bit;
	int		dif;

	dif = 0;
	bit = 0;
	while (bit != 4)
	{
		if (i % 4 == 0 && i != 0)
			dif += x - 4;
		if (ft_state_bit(input->map, i) == 1)
		{
			out[i + input->x + input->y * x + dif] = input->letter;
			bit++;
		}
		if (out[i] == '\n')
			i++;
		i++;
	}
	return (out);
}

char			*ft_display(t_t *input)
{
	char	*out;
	int		i;
	int		x;

	i = 0;
	if (!(out = (char*)malloc((input->x * input->x + input->x) + 1)))
		return (NULL);
	ft_memset(out, '.', input->x * input->x + input->x);
	while (i != (input->x * input->x + input->x))
	{
		if ((i + 1) % (input->x + 1) == 0 && i != 0)
			out[i] = '\n';
		i++;
	}
	out[i] = '\n';
	ft_putstr(out);
	x = input->x + 1;
	while (input->letter != 'A')
	{
		input--;
		ft_display_t(out, x, 0, input);
	}
	ft_putstr(out);
	return (out);
}
/*
int main ()
{
	t_t toto[9];

	toto[0].map = 4369;
	toto[0].x = 0;
	toto[0].y = 0;
	toto[0].dx = 1;
	toto[0].dy = 4;
	toto[0].letter = 'A';

	toto[1].map = 15;
	toto[1].x = 1;
	toto[1].y = 0;
	toto[1].dx = 4;
	toto[1].dy = 1;
	toto[1].letter = 'B';

	toto[2].map = 71;
	toto[2].x = 1;
	toto[2].y = 1;
	toto[2].dx = 3;
	toto[2].dy = 2;
	toto[2].letter = 'C';

	toto[3].map = 54;
	toto[3].x = 2;
	toto[3].y = 4;
	toto[3].dx = 3;
	toto[3].dy = 2;
	toto[3].letter = 'D';

	toto[4].map = 51;
	toto[4].x = 4;
	toto[4].y = 1;
	toto[4].dx = 2;
	toto[4].dy = 2;
	toto[4].letter = 'E';

	toto[5].map = 99;
	toto[5].x = 1;
	toto[5].y = 2;
	toto[5].dx = 3;
	toto[5].dy = 2;
	toto[5].letter = 'F';

	toto[6].map = 547;
	toto[6].x = 4;
	toto[6].y = 3;
	toto[6].dx = 2;
	toto[6].dy = 3;
	toto[6].letter = 'G';

	toto[7].map = 39;
	toto[7].x = 0;
	toto[7].y = 4;
	toto[7].dx = 3;
	toto[7].dy = 2;
	toto[7].letter = 'H';

	toto[8].map = 0;
	toto[8].x = 6;
	toto[8].y = 0;
	toto[8].dx = 0;
	toto[8].dy = 0;
	toto[8].letter = 0;


	ft_display(toto + 8);
	return(0);
}*/
