# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollier <pollier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 02:49:06 by pollier           #+#    #+#              #
#    Updated: 2015/12/17 18:41:07 by pollier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
SOURCE =	main.c \
			options.c \
			print_file_mode.c \
			print_l.c \
			print_user_group.c \
			print.c \
			target.c
OBJ = $(SOURCE:.c=.o)
FLAGS = -Wall -Wextra -Werror
NAME = ft_ls

%.o: %.c
	$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -j -C $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -Rf $(NAME)
	@rm -Rf $(DSYM)
	@make fclean -C $(LIBFT_PATH)

db: re
	lldb ./$(NAME)

test: re
	./$(NAME) -arRlt *

val: re all
	clear
	valgrind $(VALGRIND_FLAGS) ./$(NAME) -arRlt *

re: fclean all

.PHONY: all clean fclean db test val re
