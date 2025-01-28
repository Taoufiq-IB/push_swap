NAME = push_swap
SRC = ft_atoi.c ft_split.c push_functions.c push_swap.c utils.c stack_utils.c reverse_functions.c rotate_functions.c swap_functions.c sorting.c lst_utils.c sort_five_less.c

OBJ = $(SRC:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
