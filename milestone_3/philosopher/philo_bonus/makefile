# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:53:01 by fre007            #+#    #+#              #
#    Updated: 2025/03/22 10:44:35 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

FILES = philosofer_bonus.c ft_atoi.c support_function_bonus.c table_work_bonus.c
CFLAGS = -pthread -Wall -Werror -Wextra -g
VFLAGS = -pthread -Wall -Werror -Wextra -g -fsanitize=thread

all:
	@cc $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: