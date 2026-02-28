/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:43 by cwon              #+#    #+#             */
/*   Updated: 2026/02/28 16:19:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include <stddef.h>

# include "color_bonus.h"
# include "vector_bonus.h"

typedef struct s_dispatcher	t_dispatcher;
typedef struct s_list		t_list;
typedef struct s_parser		t_parser;
typedef struct s_scene		t_scene;
typedef struct s_spotlight	t_spotlight;

struct s_parser
{
	char			*line;
	const char		*id;
	int				fd;
	t_dispatcher	*dispatcher;
	t_list			*list;
	t_scene			*scene;
};

// convert_utils_bonus.c
void		check_rgb(t_parser *p, char **arr);
void		check_vector(t_parser *p, char **arr);

// convert_bonus.c
double		get_float(t_parser *p, size_t index);
double		get_fov(t_parser *p, size_t index);
double		get_ratio(t_parser *p, size_t index);
t_color		get_color(t_parser *p, size_t index);
t_vector	get_vector(t_parser *p, size_t index, bool normalized);

// parse_elements_bonus.c
void		parse_ambient(t_parser *p);
void		parse_camera(t_parser *p);
void		parse_light(t_parser *p);
void		parse_spotlight(t_parser *p);

// parse_objects_bonus.c
void		parse_cylinder(t_parser *p);
void		parse_paraboloid(t_parser *p);
void		parse_plane(t_parser *p);
void		parse_sphere(t_parser *p);

// parse_spotlight_bonus.c
void		append_spotlight(t_parser *p, t_spotlight *ptr);

// parse_utils_bonus.c
void		*parser_malloc(t_parser *p, size_t size);
void		check_multiple_declarations(t_parser *p, const void *ptr);
void		check_commas(t_parser *p, const char *str);
void		check_token_count(t_parser *p, size_t expected);

// parse_bonus.c
void		parse(const char *filename, t_scene *scene);

// parser_bonus.c
void		flush_parser(t_parser *p);
void		init_parser(t_parser *p, const char *path, t_scene *s);
void		parser_error(t_parser *p, const char *msg);
void		reset_parser(t_parser *p);

#endif
