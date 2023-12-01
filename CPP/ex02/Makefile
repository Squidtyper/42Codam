# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/14 12:50:07 by lizhang       #+#    #+#                  #
#    Updated: 2023/08/30 15:58:16 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe
CC			= c++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++11 #-fsanitize=address -g
INCLUDE		= -IPmergeMe.hpp
SRC			= main.cpp PmergeMe.cpp
OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re