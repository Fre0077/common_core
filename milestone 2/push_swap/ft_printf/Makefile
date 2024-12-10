# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:33:30 by fde-sant          #+#    #+#              #
#    Updated: 2024/12/10 08:27:23 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
LIBFTDIR = ../libft/
LIBFT = ../libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

FILE =	ft_printf.c ft_putbase.c ft_putbase_long.c ft_putnbr_un.c ft_putnbr_fd.c \
		ft_putchar_fd.c ft_putstr_fd.c

OBJ = $(FILE:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)	

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all

.SILENT: