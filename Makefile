# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 15:11:00 by cwon              #+#    #+#              #
#    Updated: 2025/11/04 14:50:05 by cwon             ###   ########.fr        #
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
	parser/dispatcher.c \
	parser/parse_ambient.c \
	parser/parse_camera.c \
	parser/parse_cylinder.c \
	parser/parse_light.c \
	parser/parse_plane.c \
	parser/parse_sphere.c \
	parser/parse.c \
	parser/parser.c

SCENE_SRC := \
	scene/scene.c

UTIL_SRC := 

MINIRT_SRC := \
	miniRT/mini_rt.c \
	miniRT/validate.c

# SRC_BONUS :=

MAIN := main.c

ALL_SRC := \
	$(OBJECTS_SRC) \
	$(PARSER_SRC) \
	$(SCENE_SRC) \
	$(UTIL_SRC) \
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
