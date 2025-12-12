# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 15:11:00 by cwon              #+#    #+#              #
#    Updated: 2025/12/12 14:10:27 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT
BONUS_NAME := miniRT_bonus

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP -O3 -g

MANDATORY_SRC_DIR := mandatory/src
MANDATORY_INC_DIR := mandatory/include

BONUS_SRC_DIR := bonus/src
BONUS_INC_DIR := bonus/include

OBJ_DIR := obj

MLX_DIR := minilibx-linux
LIBFT_DIR := libft

MLX := $(MLX_DIR)/libmlx.a
LIBFT := $(LIBFT_DIR)/libft.a

MLX_FLAGS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

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
	renderer/hit_cylinder.c \
	renderer/hit_plane.c \
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
	utils/vector_projection.c \
	utils/vector.c

MINIRT_SRC := \
	miniRT/mini_rt.c \
	miniRT/validate.c

MAIN := main.c

MANDATORY_SRC := \
	$(OBJECTS_SRC) \
	$(PARSER_SRC) \
	$(RENDERER_SRC) \
	$(SCENE_SRC) \
	$(UTILS_SRC) \
	$(MINIRT_SRC) \
	$(MAIN)

OBJECTS_BONUS_SRC := \
	objects/object_bonus.c

PARSER_BONUS_SRC := \
	parser/convert_utils_bonus.c \
	parser/convert_bonus.c \
	parser/dispatcher_bonus.c \
	parser/parse_elements_bonus.c \
	parser/parse_objects_bonus.c \
	parser/parse_utils_bonus.c \
	parser/parse_bonus.c \
	parser/parser_bonus.c

RENDERER_BONUS_SRC := \
	renderer/hit_bonus.c \
	renderer/hit_cylinder_bonus.c \
	renderer/hit_paraboloid_bonus.c \
	renderer/hit_plane_bonus.c \
	renderer/hit_sphere_bonus.c \
	renderer/lambertian_bonus.c \
	renderer/minilibx_bonus.c \
	renderer/phong_bonus.c \
	renderer/render_bonus.c \
	renderer/renderer_bonus.c

SCENE_BONUS_SRC := \
	scene/camera_bonus.c \
	scene/scene_bonus.c

UTILS_BONUS_SRC := \
	utils/basis_bonus.c \
	utils/color_bonus.c \
	utils/matrix_transform_bonus.c \
	utils/matrix_bonus.c \
	utils/point_bonus.c \
	utils/quadratic_bonus.c \
	utils/ray_bonus.c \
	utils/vector_norm_bonus.c \
	utils/vector_product_bonus.c \
	utils/vector_projection_bonus.c \
	utils/vector.c

MINIRT_BONUS_SRC := \
	miniRT/mini_rt_bonus.c \
	miniRT/validate_bonus.c

MAIN_BONUS := main_bonus.c

BONUS_SRC := \
	$(OBJECTS_BONUS_SRC) \
	$(PARSER_BONUS_SRC) \
	$(RENDERER_BONUS_SRC) \
	$(SCENE_BONUS_SRC) \
	$(UTILS_BONUS_SRC) \
	$(MINIRT_BONUS_SRC) \
	$(MAIN_BONUS)

MANDATORY_OBJ := $(addprefix $(OBJ_DIR)/, $(MANDATORY_SRC:.c=.o))
BONUS_OBJ := $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

DEP := $(MANDATORY_OBJ:.o=.d) $(BONUS_OBJ:.o=.d)

MANDATORY_INC := $(shell find $(MANDATORY_INC_DIR) -type d)
BONUS_INC     := $(shell find $(BONUS_INC_DIR) -type d)

MANDATORY_CFLAGS := $(addprefix -I, $(MANDATORY_INC))
BONUS_CFLAGS     := $(addprefix -I, $(BONUS_INC))

CFLAGS += -I$(MLX_DIR) -I$(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MLX) $(LIBFT) $(MANDATORY_OBJ)
	$(CC) $(CFLAGS) $(MANDATORY_CFLAGS) $(MANDATORY_OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $@

$(BONUS_NAME): $(MLX) $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(MANDATORY_CFLAGS) $(BONUS_CFLAGS) $(BONUS_OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(MANDATORY_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MANDATORY_CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MANDATORY_CFLAGS) $(BONUS_CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all bonus clean fclean re
