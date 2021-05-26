NAME	=	push_swap
CC		=	clang
HEADER	=	includes/pushswap.h
OBJDIR	=	object
SRC		=	pushswap.c \
			srcs/utils.c srcs/utils2.c \
			srcs/in-utils.c \
			srcs/parsing.c srcs/split.c \
			\
			srcs/swappers.c srcs/swappers2.c srcs/rev_med.c \
			srcs/sort.c

OBJ 	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus