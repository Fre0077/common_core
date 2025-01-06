# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:50:41 by fde-sant          #+#    #+#              #
#    Updated: 2025/01/06 16:57:42 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
CC = cc
CFLAGS = -g -Werror -Wall -Wextra

FILE =	test.c texture.c reading_map.c

OBJ = $(FILE:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "created .a"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "removed .o"

fclean:		clean
	@rm -rf $(NAME)
	@echo "removed .a"

re:			fclean all

.SILENT:

run:
	@make re
	@make clean
	@clear
	@cc test.c so_long.a -g -Lmlx -lmlx -lXext -lX11 -lm -Lmlx -lmlx -lXext -lX11 -lm -o "a"