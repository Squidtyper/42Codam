# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/07 13:50:23 by lizhang       #+#    #+#                  #
#    Updated: 2023/05/19 17:57:27 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= intern
CC				= g++
CPPFLAGS		= -Wall -Werror -Wextra -std=c++98
INCLUDE			= -IBureaucrat.hpp -IAForm.hpp -IShrubberyCreationForm.hpp \
				-IRobotomyRequestForm.hpp -IPresidentialPardonForm.cpp \
				-IIntern.hpp
SRC				= AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
				Intern.cpp main.cpp
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