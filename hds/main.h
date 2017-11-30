/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:02:22 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/30 14:20:09 by kdouveno         ###   ########.fr       */
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

typedef	unsigned long t_map[4];
typedef struct		s_t
{
	t_map			map;
	char			letter;
}					t_t;

int					ft_check(char *c);
int					ft_opfiro(char *path);
unsigned int		ft_filesize(int fd);
char				*ft_fibuf(char *path, unsigned int size);
char				*ft_read(int fd);
int					ft_validate(t_t *tetros);
t_t					ft_strtot(char *s);
int					ft_fillit(int argc, char **argv);
t_t					*ft_parse(char *s);
int					ft_place(t_t *tetros, t_map trymap,
		unsigned char size);
char				ft_bitat(unsigned long map, unsigned char pos);
char				ft_count_link(unsigned long map, int pos);
int					ft_resolve(t_t *tetros, unsigned char size);
void				ft_prtabt(unsigned long map);
void				ft_prtest(t_map);

#endif
