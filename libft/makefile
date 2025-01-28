# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 17:51:57 by fre007            #+#    #+#              #
#    Updated: 2025/01/28 20:57:30 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g

FILE = ft_printf.c ft_putbase.c ft_putbase_long.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putnbr_fd.c isnumber.c isletter.c ft_itoa.c ft_atoi.c ft_calloc.c\
	ft_callocn.c find_cinstr.c find_ninarr.c

OBJ = $(FILE:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "created libft.a"

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "removed libft.o"

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "removed libft.a"

re:		fclean all

.SILENT: