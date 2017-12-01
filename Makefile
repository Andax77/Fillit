NAME = fillit

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
HDDIR = bin/

OBJS = $(SRCFILES:.c=.o)
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))

LIBS = ft
LIBSDIR = libft

RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
MAGENTA = \x1b[35m
WHITE = \x1b[37m

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): o
	@gcc $(FLAGS) $(OBJS) -L$(LIBSDIR) -l$(LIBS) -o $(NAME)
	@make line
	@echo "$(YELLOW)    .o and executable created    $(WHITE)"
	@make line

clean:
	@rm -rf $(OBJS)
	@echo "$(GREEN)[----------------]"
	@echo "[$(YELLOW)     all .o     $(GREEN)]"
	@echo "[$(YELLOW)    has been    $(GREEN)]"
	@echo "[$(YELLOW)    Cleaned     $(GREEN)]"
	@echo "[----------------]$(WHITE)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)[----------------]"
	@echo "[$(YELLOW)  Successfully  $(GREEN)]"
	@echo "[$(YELLOW)    cleared     $(GREEN)]"
	@echo "[$(YELLOW)   executable   $(GREEN)]"
	@echo "[----------------]$(WHITE)"

re: fclean
	@make
	@echo "$(GREEN)[----------------]"
	@echo "[$(YELLOW)     Remake     $(GREEN)]"
	@echo "[$(YELLOW)      made      $(GREEN)]"
	@echo "[$(YELLOW)  Successfully  $(GREEN)]"
	@echo "$(GREEN)[----------------]$(WHITE)"

o:
	@gcc -c $(SRCS)

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
	@echo "$(YELLOW)  Here is the tetriminos tested  $(WHITE)"
	@make line
	@sh replace.sh
	@make line

error:
	@echo "$(RED)[----------------]"
	@echo "$(RED)[   ! There !    ]"
	@echo "$(RED)[   ! is no !    ]"
	@echo "$(RED)[   ! ERROR !    ]"
	@echo "$(RED)[----------------]"
