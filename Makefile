NAME = push_swap
NAME_BONUS = checker

MANDATORY = ./mandatory/ft_atoi.c \
			./mandatory/ft_split.c \
			./mandatory/lst_utils.c \
			./mandatory/push_functions.c \
			./mandatory/push_swap.c \
			./mandatory/utils.c \
			./mandatory/stack_utils.c \
			./mandatory/reverse_functions.c \
			./mandatory/rotate_functions.c \
			./mandatory/swap_functions.c \
			./mandatory/sorting.c \
			./mandatory/sort_five_less.c
BONUS = ./bonus/ft_atoi.c \
		./bonus/ft_split.c \
		./bonus/push_functions.c \
		./bonus/checker.c \
		./bonus/utils.c \
		./bonus/stack_utils.c \
		./bonus/reverse_functions.c \
		./bonus/rotate_functions.c \
		./bonus/swap_functions.c \
		./bonus/operations.c \
		./bonus/lst_utils.c \
		./bonus/get_next_line_utils.c \
		./bonus/get_next_line.c \
		./bonus/checker_utils.c \
		./bonus/norm_main.c

OBJ = $(MANDATORY:.c=.o)
OBJBONUS = $(BONUS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(NAME_BONUS): $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $@

mandatory/%.o: mandatory/%.c ./mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c ./bonus/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

