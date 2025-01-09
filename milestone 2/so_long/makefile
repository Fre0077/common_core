# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:50:41 by fde-sant          #+#    #+#              #
#    Updated: 2025/01/09 09:25:14 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
FT_PRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/ft_printf.a
LIBFT = ft_printf/libft/libft.a
CC = cc
CFLAGS = -g -Werror -Wall -Wextra

FILE =	so_long.c create_texture.c put_texture.c reading_map.c checking_map.c\
		move.c

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
	@cc so_long.c so_long.a -g -Lmlx -lmlx -lXext -lX11 -lm -Lmlx -lmlx -lXext -lX11 -lm -o "a"

generic: run
	./a "maps/generic.ber"

debug: 
	lldb ./a "maps/generic.ber"

valgrind: 
	valgrind --leak-check=full --track-origins=yes ./a "maps/generic.ber"

small: run
	./a "maps/small.ber"
	
precis: run
	./a "maps/precis.ber"