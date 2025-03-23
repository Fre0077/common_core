# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 09:20:40 by fde-sant          #+#    #+#              #
#    Updated: 2025/03/22 10:44:51 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FILES = philosofer.c ft_atoi.c support_function.c table_work.c
CFLAGS = -pthread -Wall -Werror -Wextra -g
VFLAGS = -pthread -Wall -Werror -Wextra -g -fsanitize=thread

all:
	@cc $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: