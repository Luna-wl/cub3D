NAME := cub3D

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g

SRCS_DIR := ./srcs
SRCS := $(shell find $(SRCS_DIR) -name '*.c')
HEADER_I := -I$(SRCS_DIR)

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
LIB_I := -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(LIB_I) $(HEADER_I) -o $@

$(LIBFT):
	@make -C ./libft

norm:
	@echo "---- NORMINETTE ----"
	@norminette -R CheckDefine src/*.h
	@norminette -R CheckForbiddenSourceHeader src/*.c
	@echo "---- THANK YOU ^w^Y ----"

clean:
	@make fclean -C ./libft
	@rm -rf *.dSYM *.o $(NAME)

fclean: clean

re: fclean all libft

.PHONY: clean fclean re norm libft
