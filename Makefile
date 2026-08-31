NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/algorithms/sort_adaptive.c \
              $(SRC_DIR)/algorithms/sort_complex.c \
              $(SRC_DIR)/algorithms/sort_medium.c \
              $(SRC_DIR)/algorithms/sort_simple.c \
              $(SRC_DIR)/algorithms/sort_three.c \
              $(SRC_DIR)/operations/op_push.c \
              $(SRC_DIR)/operations/op_rotate.c \
              $(SRC_DIR)/operations/op_rotate_reverse.c \
              $(SRC_DIR)/operations/op_swap.c \
              $(SRC_DIR)/parsing/parsing.c \
              $(SRC_DIR)/stack/free_stack.c \
              $(SRC_DIR)/stack/is_sorted.c \
              $(SRC_DIR)/stack/stack_add_to_top.c \
              $(SRC_DIR)/stack/stack_new.c \
              $(SRC_DIR)/stack/stack_utils.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re