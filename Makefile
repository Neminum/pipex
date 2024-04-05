# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:40:37 by tsurma            #+#    #+#              #
#    Updated: 2024/04/05 15:16:10 by tsurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
NAME_B	= pipex_bonus

SRC =	scrs/pipex.c\
		scrs/pipex_utils.c
OBJ = $(SRC:.c=.o)

SRC_B =	scrs/pipex_bonus.c\
		scrs/pipex_utils.c\
		scrs/pipex_utils_bonus.c
OBJ_B =	$(SRC_B:.c=.o)

CC =		cc
CFLAGS =	-Wall -Werror -Wextra -g3
MAKEFLAGS =	--no-print-directory


all:	$(NAME)

bonus:	$(NAME_B)

.SILENT $(NAME) : $(OBJ)
	@ make re -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

$(NAME_B) : $(OBJ_B)
	@make re -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B) libft/libft.a

clean :
	make clean -C ./libft
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME) $(NAME_B)

re:			fclean all

re_bonus:	fclean bonus

.PHONY:		all clean fclean re bonus bonus_re
