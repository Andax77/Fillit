NAME = fillit

CC = gcc

SRCFILES = ft_check.c\
    ft_count_link.c\
    ft_main.c\
    ft_parse.c\
    ft_read.c\
    ft_resolve.c\
    ft_validate.c\
	ft_map_shifts.c\
	ft_map_operators.c\
	ft_display.c\

SRCDIR = bin/

OBJS = $(SRCFILES:.c=.o)

LIBDIR = libft/
LIB = libft.a
LIBSRCS = $(wildcard $(LIBDIR)*.c)
LIBOBJS = $(lib:.c=.o)

RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
MAGENTA = \x1b[35m
WHITE = \x1b[37m

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@echo creation du fillit
	@$(CC) $(FLAGS) -o $@ $^

%.o: $(SRCDIR)%.c
	@echo creation des .o
	@gcc $(FLAGS) -c $^

$(LIB):
	@echo creatin du libft.a
	@cd $(LIBDIR); make; mv $(LIB) ..; mv *.o ..; cd ..

clean:
	@rm -rf *.o
	@cd $(LIBDIR); make clean; cd ..

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIB)
	@cd $(LIBDIR); make fclean; cd ..

re: fclean all

line:
	@echo "$(MAGENTA)---------------------------------$(WHITE)"

retest: re testa

testa: gene cat test

test:
	@make line
	@echo "$(YELLOW)          Fillit output          $(WHITE)"
	@make line
	@echo
	@./$(NAME) map
	@echo
	@make line

gene:
	@sh gene.sh 12

cat:
	@make line
	@echo "$(YELLOW)  Here are the tetriminos tested  $(WHITE)"
	@make line
	@sh replace.sh
	@make line

error:
	@echo "$(RED)[----------------]"
	@echo "$(RED)[   ! There !    ]"
	@echo "$(RED)[   ! is no !    ]"
	@echo "$(RED)[   ! ERROR !    ]"
	@echo "$(RED)[----------------]"
