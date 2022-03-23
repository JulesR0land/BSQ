.PHONY: all $(NAME) clean fclean re run-tests

SRC			=	main.c					\
				src/get_file.c			\
				src/char_to_int_array.c \
				src/algo.c

NAME		=	bsq

CC			=	gcc

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I include/

OBJ			=	$(SRC:.c=.o)

all:
	make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all