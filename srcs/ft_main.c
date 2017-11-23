/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:23:05 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/23 15:18:19 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hds/main.h"

int		ft_fillit(int argc, char **argv)
{
	char	*buf;

	if (!(buf = ft_fibuf(argv[1], ft_filesize(ft_opfiro(argv[1])))))
		return (1);
	if (ft_check(buf))
		return (1);
	ft_parse(buf);
	printf("tout va bien");
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit target_map_file", 2);
		return (0);
	}
	if (ft_fillit(argc, argv))
	{
		ft_putstr_fd("error", 2);
		return (0);
	}
	
	return (0);
}
