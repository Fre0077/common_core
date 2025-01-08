# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:40:02 by fde-sant          #+#    #+#              #
#    Updated: 2025/01/08 16:52:08 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -g -Wall -Wextra -Werror

FILES =	ft_calloc.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_strlen.c ft_putnbr_un.c ft_findc.c  ft_countc.c\
		ft_freematrix.c ft_strlen.c ft_diff.c ft_print_matrix.c\
		ft_distance.c ft_countc_matrix.c

OBJ = $(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(BONUS_OBJ)

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all
