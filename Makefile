NAME = fdf
SRC = 	main.c \
		display.c \
		bresenham.c \
		colors.c \
		events.c \
		utils.c \
		parse.c \
		tutorial.c \
		exit.c
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
CC = gcc
LIB = libft
FRAME = -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
LIBDONE = libft/libft.a

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIB)
	$(CC) $(SRC) $(LIBDONE) $(FRAME) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean	
re: fclean all
