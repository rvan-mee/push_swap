SRC = main.c				\
	  sorting.c				\
	  lowest.c				\
	  bucket_sort.c			\
	  highest.c				\
	  radix.c				\
	  bit.c					\
	  sort_to_a.c			\
	  sort_a_helper.c		\

BNS_SRC =	checker.c		\

SHARED_SRC =	rotate.c			\
	  			parsing.c			\
	  			position_sort.c		\
	 			push.c				\
	 			swap.c				\

CC = gcc

OBJDIR = objs

CFLAGS = -Wall -Werror -Wextra
## -fsanitize=address -g
TARGET = push_swap

BNS_TARGET = checker

OBJ = $(addprefix objs/, $(SRC:.c=.o) $(SHARED_OBJ))

BNS_OBJ = $(addprefix objs/, $(BNS_SRC:.c=.o) $(SHARED_OBJ))

SHARED_OBJ = $(SHARED_SRC:.c=.o)

$(TARGET): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) $(CFLAGS) libft/libft.a -o $(TARGET)

$(BNS_TARGET): $(BNS_OBJ)
	@make -C libft
	@$(CC) $(BNS_OBJ) $(CFLAGS) libft/libft.a -o $(BNS_TARGET)

$(OBJDIR)/%.o: src/mandatory/%.c src/mandatory/push_swap.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/bonus/%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/shared/%.c src/shared/shared.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo cleaning .o files
	@make -C libft clean
	@rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	@echo cleaning folders
	@rm -f libft/libft.a
	@rm -f $(TARGET)
	@rm -f $(BNS_TARGET)

all: $(TARGET) $(BNS_TARGET)

bonus: $(BNS_TARGET)

re: fclean all

.PHONY: all clean fclean re bonus