# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:20:40 by fde-sant          #+#    #+#              #
#    Updated: 2025/03/05 09:20:56 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosofers

FILES = test.c ft_atoi.c
CFLAGS = -pthread -Wall -Werror -Wextra -g
VFLAGS = -pthread -Wall -Werror -Wextra -g -fsanitize=thread

all:
	@cc $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

valgrind:
	@cc $(FILES) $(VFLAGS) -o $(NAME)

run:
	make && clear && ./philosofers 5 900 200 100

.SILENT: