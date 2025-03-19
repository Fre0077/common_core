# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:20:40 by fde-sant          #+#    #+#              #
<<<<<<< HEAD:milestone_3/philosopher/makefile
#    Updated: 2025/03/17 09:52:46 by fde-sant         ###   ########.fr        #
=======
#    Updated: 2025/03/19 08:33:08 by fre007           ###   ########.fr        #
>>>>>>> 56e614f9f1fa37d6d55d0f7806e8065b643b17be:milestone_3/philosopher/philo/makefile
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
	make && clear && ./philosofers 19 210 90 71 2

hell:
	make && clear && valgrind --tool=helgrind  --log-file=valgrind_output.txt ./philosofers 5 100 200 100

vall:
	make && clear && valgrind --leak-check=yes --track-origins=yes --log-file=valgrind_output.txt ./philosofers 5 100 200 100

.SILENT: