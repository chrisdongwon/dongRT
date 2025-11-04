/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:43 by cwon              #+#    #+#             */
/*   Updated: 2025/11/04 15:30:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_dispatcher	t_dispatcher;
typedef struct s_list		t_list;
typedef struct s_parser		t_parser;
typedef struct s_scene		t_scene;

struct s_parser
{
	char			*line;
	int				fd;
	t_list			*list;
	t_scene			*scene;
	t_dispatcher	*subparser;
};

// parse_ambient.c
void	parse_ambient(t_parser *p);

// parse_camera.c
void	parse_camera(t_parser *p);

// parse_cylinder.c
void	parse_cylinder(t_parser *p);

// parse_light.c
void	parse_light(t_parser *p);

// parse_plane.c
void	parse_plane(t_parser *p);

// parse_sphere.c
void	parse_sphere(t_parser *p);

// parse.c
void	parse(const char *filename, t_scene *scene);

// parser.c
void	flush_parser(t_parser *p);
void	init_parser(t_parser *p, const char *filename, t_scene *scene);
void	parser_error(t_parser *p, const char *context, const char *msg);
void	reset_parser(t_parser *p);

#endif
