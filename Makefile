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

NAME = push_swap

#  find *.c | xargs echo

SRCS = argument_validation.c argument_validation_utils.c cost.c cost_b.c\
	exit_handler.c main.c move_B.c move_algo.c sort.c sort_utils.c stack_b_move.c stack_move.c\
	operations/push.c operations/rev_rot.c operations/rot.c operations/swap.c


OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
