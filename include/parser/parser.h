/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:43 by cwon              #+#    #+#             */
/*   Updated: 2025/11/05 15:24:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stddef.h>

#include "color.h"

typedef struct s_dispatcher	t_dispatcher;
typedef struct s_list		t_list;
typedef struct s_parser		t_parser;
typedef struct s_scene		t_scene;

struct s_parser
{
	char			*line;
	const char		*id;
	double			ratio;
	int				fd;
	t_color			color;
	t_dispatcher	*subparser;
	t_list			*list;
	t_scene			*scene;
};

// parse_ambient.c
void	parse_ambient(t_parser *p);

// parse_camera.c
void	parse_camera(t_parser *p);

// parse_convert.c
double	get_ratio(t_parser *p, size_t index);

// parse_cylinder.c
void	parse_cylinder(t_parser *p);

// parse_light.c
void	parse_light(t_parser *p);

// parse_plane.c
void	parse_plane(t_parser *p);

// parse_sphere.c
void	parse_sphere(t_parser *p);

// parse_utils.c
void	check_multiple_declarations(t_parser *p, void *ptr);
void	check_rgb(t_parser *p, char **arr);
void	check_terminal_comma(t_parser *p, const char *str);
void	check_token_count(t_parser *p, size_t expected);

// parse.c
void	parse(const char *filename, t_scene *scene);

// parser.c
void	flush_parser(t_parser *p);
void	init_parser(t_parser *p, const char *filename, t_scene *scene);
void	parser_error(t_parser *p, const char *msg);
void	reset_parser(t_parser *p);

#endif
