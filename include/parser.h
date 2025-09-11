/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:34:01 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:09:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

# define MAX_TOKENS 7

typedef enum e_parser_status	t_parser_status;
typedef struct s_parser			t_parser;
typedef struct s_rgb			t_rgb;
typedef struct s_scene			t_scene;
typedef struct s_vector			t_vector;

struct							s_rgb;
struct							s_scene;
struct							s_vector;

enum e_parser_status
{
	PARSER_EMPTY,
	PARSER_ERROR,
	PARSER_OK
};

struct s_parser
{
	bool	has_ambient;
	bool	has_camera;
	bool	has_light;
};

// parse_elements.c
t_parser_status	parse_ambient(char **tokens, int count, t_scene *scene, \
t_parser *parser);
t_parser_status	parse_camera(char **tokens, int count, t_scene *scene, \
t_parser *parser);
t_parser_status	parse_light(char **tokens, int count, t_scene *scene, \
t_parser *parser);

// parse_objects.c
t_parser_status	parse_sphere(char **tokens, int count, t_scene *scene);
t_parser_status	parse_plane(char **tokens, int count, t_scene *scene);
t_parser_status	parse_cylinder(char **tokens, int count, t_scene *scene);

// parse_util.c
bool			parse_double(const char *str, double *out);
bool			parse_int(const char *s, int *out);
bool			parse_rgb_str(char *str, t_rgb *color);
bool			parse_vector_str(char *str, t_vector *vec, bool is_normalized);

// parse.c
void			parse(const int argc, char **argv);

// parser.c
void			init_parser(t_parser *parser);
void			validate_parser(t_parser *parser);

// util.c
bool			has_rt_extension(const char *filename);
char			*trim_whitespace(char *str);
int				get_tokens(char *tokens[MAX_TOKENS], char *line);
void			fatal(const char *msg);
void			usage_message(char **argv);

#endif
