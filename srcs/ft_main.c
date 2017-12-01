/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:00:13 by kdouveno          #+#    #+#             */
/*   Updated: 2017/12/01 16:26:13 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

unsigned char	ft_start_size(t_t *tetros)
{
	int i;

	i = 0;
	while (tetros->letter)
	{
		i++;
		tetros++;
	}
	return (i);
}

int				ft_fillit(int argc, char **argv)
{
	char			*buf;
	t_t				*tetros;
	int				i;
	unsigned char	size;

	if (!(buf = ft_fibuf(argv[1], ft_filesize(ft_opfiro(argv[1])))))
		return (1);
	if (ft_check(buf))
		return (1);
	if (!(tetros = ft_parse(buf)))
		return (1);
	free(buf);
	if (ft_validate(tetros))
		return (1);
	size = ft_sqrt(4 * ft_start_size(tetros));
	while (ft_resolve(tetros, size))
		size++;
	if (!(buf = ft_display(tetros, size)))
		return (1);
	free(buf);
	free(tetros);
	return (0);
}

int				main(int argc, char **argv)
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
