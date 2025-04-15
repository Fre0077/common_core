# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:30:50 by fre007            #+#    #+#              #
#    Updated: 2025/04/15 10:18:58 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(HEADERS)
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: