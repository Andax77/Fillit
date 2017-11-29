NAME = fillit

SRCFILES = ft_check.c\
    ft_count_link.c\
    ft_main.c\
    ft_parse.c\
    ft_read.c\
    ft_resolve.c\
    ft_state_bit.c\
    ft_validate.c

SRCDIR = srcs/
HDDIR = hds/

OBJS = $(SRCFILES:.c=.o)
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))

LIBS = libft.a

BLACK = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
WHITE = \x1b[37m
BGWHITE = \x1b[47m

all: $(NAME)

$(NAME): o
	@gcc $(OBJS) $(LIBS) -o $(NAME)
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
