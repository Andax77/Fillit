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

LIB = libft/libft.a

RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
MAGENTA = \x1b[35m
WHITE = \x1b[37m

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(FLAGS) -o $@ $?
	@echo "$(YELLOW)"
	@echo "sauce"

%.o: $(SRCDIR)%.c
	@gcc $(FLAGS) -c $?

$(LIB):
	@cd libft; make; make clean; cd ..

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean make

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
	@sh gene.sh 10

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
