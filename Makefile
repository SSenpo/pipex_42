NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = includes/pipex.h

SRC = src/pipex.c src/pipex_utils.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strnstr.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean:
	rm -f $(OBJ) 
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re