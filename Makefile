# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:40:37 by tsurma            #+#    #+#              #
#    Updated: 2024/03/12 20:27:43 by tsurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
NAME = pipex
MAKEFLAGS = --no-print-directory

SRC = pipex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean :
	make fclean -C libft
	@-rm -f $(OBJ)

fclean : clean
	@-rm -f $(NAME)

re : fclean all


.PHONY : clean fclean re all
