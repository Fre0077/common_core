NAME = libftprintf.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

FILE = ft_printf.c ft_putbase.c ft_putbase_long.c

OBJ = $(FILE:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@clear
	@echo "created .a"

$(LIBFT): 
	@$(MAKE) bonus -C $(LIBFTDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFTDIR)
	@clear
	@echo "removed .o"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@clear
	@echo "removed .a & .o"

re:		fclean all

run: re
	@make clean
	@clear
	@echo "runnig program..."
	@$(CC) $(CFLAGS) ft_printf.c libftprintf.a -o o
	@./o

val:
	@clear
	@valgrind --leak-check=yes --track-origins=yes ./o

.SILENT:
