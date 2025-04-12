# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:30:50 by fre007            #+#    #+#              #
#    Updated: 2025/04/08 11:52:20 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde

HEADER = zombie.hpp

FILES = main.cpp zombie.cpp zombieHorde.cpp 
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(HEADER)
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: