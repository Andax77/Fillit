/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:23:05 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/22 12:29:52 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	char	*buf;

	if (argc != 2)
		return (1);
	if (!(buf = ft_fibuf(argv[1], ft_filesize(ft_opfiro(argv[1])))))
		return (1);
	printf("%d\n", ft_check(buf));
	return 0;
}
