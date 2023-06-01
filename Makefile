# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:46:21 by tfinni            #+#    #+#              #
#    Updated: 2023/05/22 15:46:23 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRC		=	src/push_swap.c src/count_moves.c src/do_op.c src/do_stack.c src/ft_atol.c \
			src/helpers_two.c src/helpers.c src/moves.c src/operations.c src/sort_few.c \
			src/sort_small.c src/sort.c src/sorters.c src/value_finders.c
OBJ		=	$(SRC:.c=.o)
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I include
LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
