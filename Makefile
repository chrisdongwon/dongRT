# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 15:11:00 by cwon              #+#    #+#              #
#    Updated: 2025/11/15 13:56:42 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP -O3 -g

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

MLX_DIR := minilibx-linux
LIBFT_DIR := libft

OBJECTS_SRC := \
	objects/object.c

PARSER_SRC := \
	parser/convert_utils.c \
	parser/convert.c \
	parser/dispatcher.c \
	parser/parse_elements.c \
	parser/parse_objects.c \
	parser/parse_utils.c \
	parser/parse.c \
	parser/parser.c

RENDERER_SRC := \
	renderer/hit_sphere.c \
	renderer/hit.c \
	renderer/minilibx.c \
	renderer/render.c \
	renderer/renderer.c \
	renderer/shade.c

SCENE_SRC := \
	scene/camera.c \
	scene/scene.c

UTILS_SRC := \
	utils/basis.c \
	utils/color.c \
	utils/matrix_transform.c \
	utils/matrix.c \
	utils/point.c \
	utils/quadratic.c \
	utils/ray.c \
	utils/vector_norm.c \
	utils/vector_product.c \
	utils/vector.c

MINIRT_SRC := \
	miniRT/mini_rt.c \
	miniRT/validate.c

# SRC_BONUS :=

MAIN := main.c

ALL_SRC := \
	$(OBJECTS_SRC) \
	$(PARSER_SRC) \
	$(RENDERER_SRC) \
	$(SCENE_SRC) \
	$(UTILS_SRC) \
	$(MINIRT_SRC) \
	$(MAIN)

OBJ := $(addprefix $(OBJ_DIR)/, $(ALL_SRC:.c=.o))
OBJ_BONUS := $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))
DEP := $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

MLX := $(MLX_DIR)/libmlx.a
LIBFT := $(LIBFT_DIR)/libft.a

MLX_FLAGS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

INC_SUBDIRS := $(shell find $(INC_DIR) -type d)
CFLAGS += $(addprefix -I, $(INC_SUBDIRS)) -I$(MLX_DIR) -I$(LIBFT_DIR)

all: $(NAME)

# bonus: $(NAME)_bonus

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
