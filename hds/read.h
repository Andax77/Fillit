/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:19:34 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/22 11:20:24 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				ft_opfiro(char *path);
unsigned int	ft_filesize(int fd);
char			*ft_fibuf(char *path, unsigned int size);

#endif
