##
## Made by Victor Lucas
##

RM			=	rm -f

CC			=	gcc -o

SRC			=	src/main.c				\
				src/generation_map.c	\
				src/writing_onfile.c	\
				src/map_edit.c			

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-ansi -pedantic -Iinclude

NAME		=	generator

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			clean fclean all

.PHONY:		all clean fclean re
