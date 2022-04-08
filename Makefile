SRC = main.c			\
	  rotate.c			\
	  parsing.c			\
	  position_sort.c	\
	  push.c			\
	  swap.c			\
	  sorting.c			\
	  lowest.c			\
	  bucket_sort.c		\
	  highest.c			\
	  radix.c			\
	  bit.c				\
	  sort_to_a.c		\

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
## -fsanitize=address -g
TARGET = push_swap

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	@make -C libft bonus
	$(CC) $(OBJ) $(CFLAGS) libft/libft.a -o $(TARGET)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleaning .o files"
	@make -C libft clean
	rm -f $(OBJ)

fclean: clean
	@echo "cleaning folders"
	rm -f libft/libft.a
	rm -f $(TARGET)

re: fclean all

all: $(TARGET)
	@make -C libft bonus

.PHONY: all clean fclean re