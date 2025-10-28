/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:48 by cwon              #+#    #+#             */
/*   Updated: 2025/10/28 15:40:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <string.h>

#include "color.h"
#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

static double get_ambient_ratio(t_parser *parser, t_list *node)
{
	char	*token;
	double	ratio;

	token = (char *)node->content;
	if (!ft_isfloat(token))
		parser_error("parse_ambient", "ratio must be numeric", parser);
	ratio = ft_atof(token);
	if (ratio < 0.0 || ratio > 1.0)
		parser_error("parse_ambient", "ratio out of range [0.0, 1.0]", parser);
	return (ratio);
}

static t_color	get_ambient_color(t_parser *parser, t_list *node)
{
	char	**arr;
	char	*str;

	str = (char *)node->content;
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("get_ambient_color", strerror(errno), parser->scene);
	}
	if (str[ft_strlen(str) - 1] == ',' || ft_split_size(arr) != 3)
	{
		ft_split_free(arr);
		parser_error("parse_ambient", "invalid RGB format", parser);
	}

	// check if R G B are integers

	// convert to color (with ratio scaling)

	return (color(0,0,0));
}

static void	validate_ambient_argc(t_parser *parser)
{
	if (parser->scene->ambient != NULL)
		parser_error("parse_ambient", "multiple declarations", parser);
	if (ft_lstsize(parser->list) != 3)
		parser_error("parse_ambient", "invalid format", parser);
}

void	parse_ambient(t_parser *parser)
{
	t_list	*node;
	double	ratio;
	t_color	color;

	ft_printf("ambient detected\n");
	validate_ambient_argc(parser);
	node = parser->list->next;
	ratio = get_ambient_ratio(parser, node);
	node = node->next;
	color = get_ambient_color(parser, node);
	(void)color;
	(void)ratio;

	// allocate memory for ambient
	
	// set ambient w/ ratio scaling
}
