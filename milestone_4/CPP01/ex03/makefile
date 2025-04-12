# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:30:50 by fre007            #+#    #+#              #
#    Updated: 2025/04/08 16:25:24 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fight

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(HEADERS)
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: