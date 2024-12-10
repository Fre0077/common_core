# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 16:44:57 by fde-sant          #+#    #+#              #
#    Updated: 2024/12/10 16:23:03 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = index.a
LIBFTDIR = libft/
FT_PRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

FILE =	parsing.c input.c list.c list2.c p.c s.c r.c rr.c

OBJ = $(FILE:.c=.o)

all:		$(NAME) $(FT_PRINTF) $(LIBFT)

$(NAME):	$(OBJ) $(FT_PRINTF) $(LIBFT)
	@cp $(FT_PRINTF) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "created .a"

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTFDIR)	

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(FT_PRINTFDIR)
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "removed .o"

fclean:		clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(FT_PRINTFDIR)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "removed .a"

re:			fclean all

.SILENT:

run:
	@make re
	@make clean
	@clear
	@cc $(CFLAGS) push_swap.c index.a -o a