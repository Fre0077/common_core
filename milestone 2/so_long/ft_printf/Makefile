# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 08:33:50 by fde-sant          #+#    #+#              #
#    Updated: 2025/01/08 08:33:51 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILE = ft_printf.c ft_putbase.c ft_putbase_long.c

OBJ = $(FILE:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "created .a"

$(LIBFT): 
	@$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)

re:		fclean all

.SILENT: