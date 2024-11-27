NAME = libftprintf.a
LIBFT = libft/libft.a
LIBFTDIR = libft/
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

FILE = ft_printf.c ft_putbase.c ft_putbase_long.c

OBJ = $(FILE:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@ cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)

$(LIBFT): 
	@$(MAKE) bonus -C $(LIBFTDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFTDIR)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@clear

re:		fclean all

run: re
	@make clean
	@echo "runnig program..."
	@$(CC) $(CFLAGS) ft_printf.c libftprintf.a
	@./a.out

val:
	@make clean
	@echo "runnig program with valgrind..."
	@$(CC) $(CFLAGS) ft_printf.c libftprintf.a
	@valgrind --leak-check=yes --track-origins=yes ./a.out