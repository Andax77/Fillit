/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:02:22 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/04 17:33:28 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define ULLLINE 0xFFFF000000000000UL

typedef	unsigned long	t_map[4];
typedef struct			s_t
{
	t_map				map;
	char				letter;
}						t_t;

int						ft_check(char *c);
int						ft_opfiro(char *path);
unsigned int			ft_filesize(int fd);
char					*ft_fibuf(char *path, unsigned int size);
char					*ft_read(int fd);
int						ft_validate(t_t *tetros);
t_t						ft_strtot(char *s);
int						ft_fillit(char **argv, int fd);
t_t						*ft_parse(char *s);

char					ft_count_link(unsigned long map, int pos);
int						ft_resolve(t_t *tetros, unsigned char size);

void					ft_mapdiff(t_map map, t_map mask);
void					ft_mapadd(t_map map, t_map mask);
int						ft_collapse(t_map test, t_map try);
char					ft_bitat(unsigned long map, unsigned char pos);

void					ft_shiftx(t_map map, char shift);
void					ft_shifty(t_map map, char shift);
void					ft_shifty_rev(t_map map, char shift);

void					ft_prtabt(unsigned long map);
void					ft_prtest(t_map map);

char					*ft_display(t_t *input, unsigned char size);
#endif
