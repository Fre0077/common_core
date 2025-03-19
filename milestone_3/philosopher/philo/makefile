# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:20:40 by fde-sant          #+#    #+#              #
#    Updated: 2025/03/18 17:52:05 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosofer

FILES = philosofer.c ft_atoi.c support_function.c table_work.c
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
	make && clear && ./philosofers 5 800 200 100 

hell:
	make && clear && valgrind --tool=helgrind  --log-file=valgrind_output.txt ./philosofers 5 100 200 100

vall:
	make && clear && valgrind --leak-check=yes --track-origins=yes --log-file=valgrind_output.txt ./philosofers 5 100 200 100

.SILENT: