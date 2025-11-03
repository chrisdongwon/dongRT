/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:06:59 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 13:49:51 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_list	t_list;
typedef struct s_scene	t_scene;
typedef struct s_parser	t_parser;

struct					s_list;
struct					s_scene;

struct s_parser
{
	char	*line;
	int		fd;
	t_list	*list;
	t_scene	*scene;
};

// parse_ambient.c
void	parse_ambient(t_parser *parser);

// parse_camera.c
void	parse_camera(t_parser *parser);

// parse_cylinder.c
void	parse_cylinder(t_parser *parser);

// parse_plane.c
void	parse_plane(t_parser *parser);

// parse_sphere.c
void	parse_sphere(t_parser *parser);

// parse_light.c
void	parse_light(t_parser *parser);

// parse_lines.c
void	parse_lines(t_parser *parser);

// paser_list.c
void	parse_list(t_parser *parser);

// parser.c
void	init_parser(t_parser *parser, t_scene *scene, const char *path);
void	flush_parser(t_parser *parser);
void	parse(const int argc, char **argv, t_scene *scene);
void	parser_error(const char *context, const char *msg, t_parser *parser);

// split_line.c
void	split_line(t_parser *parser);

// validate_arg.c
void	validate_arg(const int argc, char **argv);

// validate_rgb.c
void	validate_rgb(char **arr, t_parser *p);

// validate_vector.c
void	validate_vector(char **arr, t_parser *p, double xyz[3]);

#endif
