# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/03 12:49:02 by lizhang       #+#    #+#                  #
#    Updated: 2023/07/12 15:45:40 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=42
RM		= rm -f

SRC		= get_next_line.c get_next_line_utils.c testmain.c
BSRC	= get_next_line_bonus.c get_next_line_utils_bonus.c testmain.c
OBJ		= $(SRC:.c=.o)
BOBJ	= $(BSRC:.c=.o)

ifdef WITBON
COBJ	= $(BOBJ)
else
COBJ	= $(OBJ)
endif

all:	$(NAME)

$(NAME):	$(COBJ)
			$(CC) $(COBJ) -o $(NAME)

bonus:
	$(MAKE) WITBON=1 all

clean:
	$(RM) $(COBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	make all clean fclean re bonus
