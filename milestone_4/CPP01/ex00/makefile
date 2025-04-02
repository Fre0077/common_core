# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:30:50 by fre007            #+#    #+#              #
#    Updated: 2025/04/02 15:08:08 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

FILES = main.cpp zombie.cpp newZombie.cpp randomChump.cpp
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all:
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: