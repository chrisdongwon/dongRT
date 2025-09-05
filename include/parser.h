/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:15:27 by cwon              #+#    #+#             */
/*   Updated: 2025/09/05 12:27:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

typedef struct s_parser	t_parser;

struct s_parser
{
	bool	ambient;
	bool	camera;
	bool	light;
};

// parser.c
void	parse(const char *filename);

// parser_util.c
bool	has_rt_extension(const char *filename);
char	*trim(char *str);
void	fatal(const char *msg);
void	init_parser(t_parser *parser);
void	validate_parser(t_parser *parser);

#endif
