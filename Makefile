# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollier <pollier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 02:49:06 by pollier           #+#    #+#              #
#    Updated: 2015/12/14 05:09:26 by pollier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
SOURCE = main.c process.c params.c target.c
FLAGS = -Wall -Wextra -Werror
NAME = ft_ls

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(FLAGS) $(SOURCE) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -j -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -Rf $(NAME)
	rm -Rf $(DSYM)
	make fclean -C $(LIBFT_PATH)

db: re
	lldb ./$(NAME)

test: re
	./$(NAME) -arRlt arg1 arg2 arg3 arg4 arg5

val: re all
	clear
	valgrind $(VALGRIND_FLAGS) ./$(NAME) -arRlt *

re: fclean all

.PHONY: all ft_ls clean fclean db test val re
