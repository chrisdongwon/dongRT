# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 15:11:00 by cwon              #+#    #+#              #
#    Updated: 2025/10/26 22:14:17 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP -O3 -g

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

PARSER_SRC := \
	parser/parse_lines.c \
	parser/parse_list.c \
	parser/parser.c \
	parser/split_line.c \
	parser/validate_arg.c

SCENE_SRC := \
	scene/camera.c \
	scene/light_info.c \
	scene/light.c \
	scene/material.c \
	scene/object.c \
	scene/scene.c \
	scene/shade.c \
	scene/surface.c

UTIL_SRC := \
	util/basis.c \
	util/color_transform.c \
	util/color.c \
	util/matrix_product.c \
	util/matrix.c \
	util/ray.c \
	util/vector_normalize.c \
	util/vector_product.c \
	util/vector_transform.c \
	util/vector.c

SRC := \
	main.c \
	miniRT.c

SRC_BONUS := 

ALL_SRC := \
	$(PARSER_SRC) \
	$(SCENE_SRC) \
	$(UTIL_SRC) \
	$(SRC)

OBJ := $(addprefix $(OBJ_DIR)/, $(ALL_SRC:.c=.o))
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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re bonus
