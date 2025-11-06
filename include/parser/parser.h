/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:43 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 16:20:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include <stddef.h>

# include "color.h"
# include "vector.h"

typedef struct s_dispatcher	t_dispatcher;
typedef struct s_list		t_list;
typedef struct s_parser		t_parser;
typedef struct s_scene		t_scene;

struct s_parser
{
	char			*line;
	const char		*id;
	int				fd;
	t_dispatcher	*subparser;
	t_list			*list;
	t_scene			*scene;
};

// convert_utils.c
void		check_rgb(t_parser *p, char **arr);
void		check_vector(t_parser *p, char **arr);

// convert.c
double		get_float(t_parser *p, size_t index);
double		get_fov(t_parser *p, size_t index);
double		get_ratio(t_parser *p, size_t index);
t_color		get_color(t_parser *p, size_t index);
t_vector	get_vector(t_parser *p, size_t index, bool normalized);

// parse_elements.c
void		parse_ambient(t_parser *p);
void		parse_camera(t_parser *p);
void		parse_light(t_parser *p);

// parse_objects.
void		parse_cylinder(t_parser *p);
void		parse_plane(t_parser *p);
void		parse_sphere(t_parser *p);

// parse_utils.c
void		*parser_malloc(t_parser *p, const size_t size);
void		check_multiple_declarations(t_parser *p, void *ptr);
void		check_commas(t_parser *p, const char *str);
void		check_token_count(t_parser *p, size_t expected);

// parse.c
void		parse(const char *filename, t_scene *scene);

// parser.c
void		flush_parser(t_parser *p);
void		init_parser(t_parser *p, const char *filename, t_scene *scene);
void		parser_error(t_parser *p, const char *msg);
void		reset_parser(t_parser *p);

#endif
