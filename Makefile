# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 15:11:00 by cwon              #+#    #+#              #
#    Updated: 2025/09/05 12:40:32 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

CC := cc
CFLAGS := -Wall -Wextra -Werror -O3 -MMD -MP

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

SRC := \
	main.c \
	miniRT.c \
	parser.c

SRC_BONUS := 

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS := $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

DEP := $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

MLX_DIR := minilibx-linux
MLX := $(MLX_DIR)/libmlx.a

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

MLX_FLAGS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

all: $(NAME)

# bonus: $(NAME)_bonus

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $@

# $(NAME)_bonus: $(MLX) $(LIBFT) $(OBJ) $(OBJ_BONUS)
#	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) -I$(INC_DIR) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re bonus
