/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:20:54 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/04 11:55:53 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int				ft_opfiro(char *path)
{
	return (open(path, O_RDONLY));
}

unsigned int	ft_filesize(int fd)
{
	int		i;
	int		ret;
	char	buf[1];

	i = 0;
	if (!fd)
		return (0);
	while ((ret = read(fd, buf, 1)))
		i++;
	return (i);
}

char			*ft_fibuf(char *path, unsigned int size)
{
	char	*out;
	int		fd;

	fd = ft_opfiro(path);
	if (!fd || !size)
		return (NULL);
	if (!(out = (char*)malloc(size + 1)))
		return (NULL);
	read(fd, out, size);
	out[size] = '\0';
	return (out);
}
