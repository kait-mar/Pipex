NAME = pipex

FLAGS = -Wextra -Werror -Wall

COMPILE = gcc

SRCS = ft_strdup.c pipex.c execution.c ft_strjoin.c \
	pipex_utils.c piping.c ft_split.c  ft_calloc.c

HEADERS = pipex.h

all: $(NAME)
$(NAME):
	$(COMPILE) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
