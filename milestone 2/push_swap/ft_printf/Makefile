# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:33:30 by fde-sant          #+#    #+#              #
#    Updated: 2024/12/09 13:42:35 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

FILE =	ft_printf.c ft_putbase.c ft_putbase_long.c ft_putnbr_un.c ft_putnbr_fd.c \
		ft_putchar_fd.c ft_putstr_fd.c

OBJ = $(FILE:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all

.SILENT: