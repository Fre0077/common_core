# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:30:50 by fre007            #+#    #+#              #
#    Updated: 2025/04/09 11:03:44 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

HEADERS = Harl.hpp

FILES = main.cpp Harl.cpp
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(HEADERS)
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: