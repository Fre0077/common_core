# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 14:38:09 by fre007            #+#    #+#              #
#    Updated: 2025/05/26 11:58:51 by fre007           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

HEADERS = RPN.hpp

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(NAME) $(HEADERS)

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