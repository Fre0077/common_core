# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 08:55:19 by fde-sant          #+#    #+#              #
#    Updated: 2024/11/26 09:56:52 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra -g

FILE = ft_printf.c

OBJ = $(FILE:.c=.o)



all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "creation of $(NAME)..."
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:	
	@echo "deleating obj..."
	@rm -f $(OBJ)

fclean:		clean
	@echo "deleating file.a..."
	@rm -f $(OBJ)

re:		fclean all clean

run:	
	@clear
	@echo "runnig program..."
	@$(CC) $(FLAGS) ft_printf.c -o o
	@./o

val:
	@clear
	@echo "runnig program..."
	@$(CC) $(FLAGS) ft_printf.c -o o
	@valgrind --leak-check=yes --track-origins=yes ./o

test:	
	@clear
	@echo "runnig program..."
	@$(CC) $(FLAGS) ft_test.c -o o
	@./o

oclean: 
	@rm -f o
	@rm -f a.out