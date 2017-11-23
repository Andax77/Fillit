NAME = Fillit

SRCS = ft_check.c\
    ft_read.c\
    main.c\

OBJS = $(SRCS:.c=.o;ft_=srcs/ft_)

all: $(NAME)

$(NAME):
	echo $(OBJS)
