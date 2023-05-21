# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/07 13:50:23 by lizhang       #+#    #+#                  #
#    Updated: 2023/05/12 18:07:17 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= form
CC				= g++
CPPFLAGS		= -Wall -Werror -Wextra -std=c++98
INCLUDE			= -IBureaucrat.hpp -IForm.hpp
SRC				= Form.cpp Bureaucrat.cpp main.cpp
RM				= rm -f
OBJ				= $(SRC:.cpp=.o)

$(NAME):		$(OBJ)
					$(CC) $(CPPFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re