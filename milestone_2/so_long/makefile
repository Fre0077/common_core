# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:50:41 by fde-sant          #+#    #+#              #
#    Updated: 2025/01/23 09:06:44 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
FT_PRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/ft_printf.a
LIBFT = ft_printf/libft/libft.a
CC = cc
CFLAGS = -g -Werror -Wall -Wextra

FILE =	so_long.c create_texture.c put_texture.c reading_map.c checking_map.c\
		move.c animation.c

OBJ = $(FILE:.c=.o)

all:		$(NAME) $(FT_PRINTF)

$(NAME):	$(OBJ) $(FT_PRINTF)
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
	@echo "removed .o"

fclean:		clean
	@rm -rf $(NAME)
	@rm -rf $(FT_PRINTF)
	@rm -rf $(LIBFT)
	@echo "removed .a"

re:			fclean all

.SILENT:

run:
	@make re
	@make clean
	@rm -rf $(FT_PRINTF)
	@rm -rf $(LIBFT)
	@clear
	@cc so_long.c so_long.a -g -Lmlx -lmlx -lXext -lX11 -o "a"

debug: 
	lldb ./a "maps/small.ber"

valgrind: 
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./a "maps/strange.ber"

generic: run
	./a "maps/generic.ber"

small: run
	./a "maps/small.ber"
	
precis: run
	./a "maps/precis.ber"

strange: run
	./a "maps/strange.ber"