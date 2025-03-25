# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 15:41:55 by fde-sant          #+#    #+#              #
#    Updated: 2025/03/25 11:07:52 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

FILES = main.cpp PhoneBook.cpp Contact.cpp
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all:
	@c++ $(FILES) $(CFLAGS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.SILENT: