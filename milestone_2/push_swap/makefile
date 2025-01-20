# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 19:53:43 by fde-sant          #+#    #+#              #
#    Updated: 2025/01/20 15:23:16 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -g -Werror -Wall -Wextra

FILE =	push_swap.c check_input.c read_input.c find_best.c algoritmh.c cheap.c\
		move_cheap.c\
		utils/ft_split.c utils/ft_atoi.c utils/allocation.c utils/ft_lstlen.c\
		moves/rrr.c moves/rrb.c moves/rra.c moves/rb.c moves/ra.c moves/pa.c\
		moves/pb.c moves/rr.c

OBJ = $(FILE:.c=.o)

all:		$(NAME)
	@cc push_swap.c $(NAME) $(CFLAGS) -o "push_swap"
	@make fclean

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "created exe"

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
