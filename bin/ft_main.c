/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:00:13 by kdouveno          #+#    #+#             */
/*   Updated: 2017/12/04 17:39:06 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int				ft_fillit(char **argv, int fd)
{
	char			*buf;
	t_t				*tetros;
	unsigned char	size;

	if (!(buf = ft_fibuf(argv[1], ft_filesize(fd))))
		return (1);
	close(fd);
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
	int fd;

	if (argc != 2 || !argv[1])
	{
		ft_putstr_fd("usage: fillit input_file\n", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || ft_fillit(argv, fd))
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	return (0);
}
