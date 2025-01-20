# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 17:44:01 by fde-sant          #+#    #+#              #
#    Updated: 2024/11/21 20:08:59 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CFLAG = -Wall -Werror -Wextra

FILE = get_next_line.c get_next_line_utils.c

OBJ = $(FILE:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) created"

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "file.o deleted"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:			fclean all 