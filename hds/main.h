#ifndef MAIN_H
# define MAIN_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

typedef struct		s_t
{
	int				map;
	char			letter;
	unsigned char	x;
	unsigned char	y;
}					t_t;

int					ft_check(char *c);
int					ft_opfiro(char *path);
unsigned int		ft_filesize(int fd);
char				*ft_fibuf(char *path, unsigned int size);
char				*ft_read(int fd);
int					ft_isvalid(char *fd);
t_t					ft_strtot(char *s);
int					ft_fillit(int argc, char **argv);
t_t					*ft_parse(char *s);

#endif
