# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 14:30:50 by fre007            #+#    #+#              #
#    Updated: 2025/04/17 08:56:09 by fde-sant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pa_vs_le

HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp Icharacter.hpp IMateriaSource.hpp MateriaSource.hpp

SRCS    = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS    = $(SRCS:.cpp=.o)
CXX     = c++
CFLAGS  = -std=c++98 -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: