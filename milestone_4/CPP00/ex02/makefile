# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 12:03:37 by fre007            #+#    #+#              #
#    Updated: 2025/03/25 16:00:03 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Tests

FILES = tests.cpp Account.cpp
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all:
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: