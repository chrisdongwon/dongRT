/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:06:59 by cwon              #+#    #+#             */
/*   Updated: 2025/10/26 22:24:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_list	t_list;
typedef struct s_scene	t_scene;

struct					s_list;
struct					s_scene;

// parse_ambient.c
void	parse_ambient(t_list *list, t_scene *scene);

// parse_camera.c
void	parse_camera(t_list *list, t_scene *scene);

// parse_light.c
void	parse_light(t_list *list, t_scene *scene);

// parse_lines.c
void	parse_lines(int fd, t_scene *scene);

// paser_list.c
void	parse_list(t_list *list, t_scene *scene);

// parse_object.c
void	parse_object(t_list *list, t_scene *scene);

// parser.c
void	parse(const int argc, char **argv, t_scene *scene);
void	parser_error(const char *context, const char *msg, t_scene *scene);

// split_line.c
t_list	*split_line(char *line, t_scene *scene);

// validate_arg.c
void	validate_arg(const int argc, char **argv);

#endif
