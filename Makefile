##
## EPITECH PROJECT, 2022
## Zappy
## File description:
## makefile
##

CC	=	gcc

SRC1	=	src/server/server.c \
		src/server/error.c \
		src/server/map.c \
		src/server/team.c \
		src/server/main.c

SRC3	=	src/menu/gameMenu.cpp \
		src/menu/sfml.cpp	\
		src/menu/gameTile.cpp\
		src/menu/gameWorld.cpp\
		src/menu/gameTile2.cpp\
		src/menu/gameWorld2.cpp\
		src/menu/gameTile3.cpp\
		src/menu/gameWorld3.cpp

OBJ1	=	$(SRC1:.c=.o)

OBJ3	=	$(SRC3:.cpp=.o)

NAME1	=	zappy_server

NAME2	=	zappy_ai

NAME3	=	zappy_gui

all:	$(NAME1) $(NAME2) $(NAME3)

$(NAME1):	$(OBJ1)
	$(CC) -o $(NAME1) $(OBJ1)

$(NAME2):
	cp src/ai/ai ./zappy_ai

$(NAME3):	$(OBJ3)
	g++ -o $(NAME3) $(OBJ3) -lsfml-graphics  -lsfml-audio -lsfml-window -lsfml-system

clean:
	find -name "*~" -delete
	find -name "*#" -delete
	find -name "*.o" -delete

fclean:	clean
	find -name $(NAME1) -delete
	find -name $(NAME2) -delete
	find -name $(NAME3) -delete

re:	fclean all

.PHONY: all clean fclean re
