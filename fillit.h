/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:24:30 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/22 13:19:23 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>

char			*ft_read(int fd);
int				ft_isvalid(char *fd);

typedef struct	s_t
{
	int			map;
	char		letter;
}				t_t;
t_t				ft_strtot(char *s);
char			*ft_fillit(t_t *tab);

#endif
