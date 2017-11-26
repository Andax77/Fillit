/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:02:22 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/24 12:02:24 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

typedef struct		s_t
{
	unsigned short	map;
	char			letter;
	unsigned char	x;
	unsigned char	y;
	unsigned char	dx;
	unsigned char	dy;
}					t_t;

int					ft_check(char *c);
int					ft_opfiro(char *path);
unsigned int		ft_filesize(int fd);
char				*ft_fibuf(char *path, unsigned int size);
char				*ft_read(int fd);
int					ft_isvalid(t_t *tetros);
t_t					ft_strtot(char *s);
int					ft_fillit(int argc, char **argv);
t_t					*ft_parse(char *s);
int					ft_collapse(t_t t1, t_t t2, int	x, int y);

#endif
