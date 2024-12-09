# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 16:44:57 by fde-sant          #+#    #+#              #
#    Updated: 2024/12/09 16:58:43 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME = index.a
FT_PRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/ft_printf.a
LIBFTDIR = libft/
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

FILE =	parsing.c list.c p.c s.c r.c rr.c

OBJ = $(FILE:.c=.o)

all:		$(NAME) $(FT_PRINTF) $(LIBFT)

$(NAME):	$(OBJ) $(FT_PRINTF) $(LIBFT)
	@cp	$(FT_PRINTF) $(NAME)
	@cp	$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "created .a"

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTFDIR)	

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)	

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

re:			fclean all clean

.SILENT:

#run: