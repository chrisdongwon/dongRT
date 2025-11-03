/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:43 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 22:31:18 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_parser	t_parser;
typedef struct s_scene	t_scene;

struct s_parser
{
	int		fd;
	char	*line;
	t_scene	*scene;
};

// parser.c
void	flush_parser(t_parser *p);
void	init_parser(t_parser *p, const char *filename, t_scene *scene);
void	parser(const char *filename, t_scene *scene);

#endif
