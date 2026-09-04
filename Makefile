NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = main.c \
              $(SRC_DIR)/algorithms/sort_adaptive.c \
              $(SRC_DIR)/algorithms/sort_complex.c \
              $(SRC_DIR)/algorithms/sort_medium.c \
              $(SRC_DIR)/algorithms/sort_simple.c \
              $(SRC_DIR)/algorithms/sort_three.c \
              $(SRC_DIR)/algorithms/sort_small.c \
			  $(SRC_DIR)/algorithms/bench.c \
              $(SRC_DIR)/operations/op_push.c \
              $(SRC_DIR)/operations/op_rotate.c \
              $(SRC_DIR)/operations/op_rotate_reverse.c \
              $(SRC_DIR)/operations/op_swap.c \
              $(SRC_DIR)/parsing/parsing.c \
              $(SRC_DIR)/libft/ft_split.c \
              $(SRC_DIR)/libft/ft_atol.c \
              $(SRC_DIR)/libft/ft_putnbr.c \
              $(SRC_DIR)/libft/ft_putstr.c \
              $(SRC_DIR)/parsing/parse_flags.c \
              $(SRC_DIR)/stack/free_stack.c \
              $(SRC_DIR)/stack/is_sorted.c \
              $(SRC_DIR)/stack/stack_add_to_top.c \
              $(SRC_DIR)/stack/stack_new.c \
              $(SRC_DIR)/parsing/disorder.c \
			  $(SRC_DIR)/parsing/ops_bench_init.c \
              $(SRC_DIR)/stack/stack_utils.c

OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o) 

RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regra genérica para compilar qualquer ficheiro .c para .o dentro da pasta obj/
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re