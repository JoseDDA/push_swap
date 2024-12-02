# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 15:33:02 by jdorazio          #+#    #+#              #
#    Updated: 2024/09/30 09:11:56 by jdorazio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

#  find *.c | xargs echo

C_FILES =  src/ft_split.c src/handle_errors.c src/init_stack.c src/input_validation.c src/main.c src/operations.c src/push_A_to_B.c src/push_B_to_A.c src/sort.c src/sort_utils.c src/split_utils.c src/stack_preparation.c src/stack_preparation_utils.c src/valid_utils.c
O_FILES = $(C_FILES:.c=.o)

INCLUDE = include/push_swap.h

CC = cc

CFLAGS += -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(O_FILES)  $(INCLUDE)
		ar rcs $(NAME) $(O_FILES)

%.o : %.cc
	$(CC)  $(CFLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
