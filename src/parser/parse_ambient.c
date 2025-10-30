/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:48 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 12:44:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

static double	get_ambient_ratio(t_parser *parser, t_list *node)
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
	double	rgb[3];

	str = (char *)node->content;
	if (str[ft_strlen(str) - 1] == ',')
		parser_error("parse_ambient", "invalid RGB format", parser);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("get_ambient_color", strerror(errno), parser->scene);
	}
	validate_rgb(arr, parser);
	rgb[0] = ft_atof(arr[0]) / 255.0;
	rgb[1] = ft_atof(arr[1]) / 255.0;
	rgb[2] = ft_atof(arr[2]) / 255.0;
	ft_split_free(arr);
	return (color(rgb[0], rgb[1], rgb[2]));
}

static void	set_ambient(t_parser *parser, t_color color, double ratio)
{
	parser->scene->ambient->r = color.r * ratio;
	parser->scene->ambient->g = color.g * ratio;
	parser->scene->ambient->b = color.b * ratio;
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
	double	ratio;
	t_color	color;
	t_list	*node;

	validate_ambient_argc(parser);
	node = parser->list->next;
	ratio = get_ambient_ratio(parser, node);
	node = node->next;
	color = get_ambient_color(parser, node);
	parser->scene->ambient = malloc(sizeof(t_color));
	if (parser->scene->ambient == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_ambient", strerror(errno), parser->scene);
	}
	set_ambient(parser, color, ratio);
}
