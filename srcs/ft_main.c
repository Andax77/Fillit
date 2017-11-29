/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:23:05 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/29 13:56:54 by kdouveno         ###   ########.fr       */
/*   Updated: 2017/11/27 16:09:03 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

unsigned char	ft_start_size(t_t *tetros)
{
	int i;

	i = 0;
	while (tetros->map)
	{
		i++;
		tetros++;
	}
	return (i);
}

int		ft_fillit(int argc, char **argv)
{
	char	*buf;
	t_t		*tetros;
	t_t		*out;
	int		i;
	unsigned char size;

	if (!(buf = ft_fibuf(argv[1], ft_filesize(ft_opfiro(argv[1])))))
		return (1);
	if (ft_check(buf))
		return (1);
	if (!(tetros = ft_parse(buf)))
			return (1);
	if (!(out = ft_parse(buf)))
			return (1);
	if(ft_validate(tetros))
		return (1);
	size = ft_sqrt(4 * ft_start_size(tetros));
	while(!ft_resolve(tetros, out, size))
		size++;
	printf("megafin\n");
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit input_file\n", 2);
		return (0);
	}
	if (ft_fillit(argc, argv))
	{
		ft_putstr_fd("error", 2);
		return (0);
	}
	return (0);
}
