/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:38 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 09:52:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"
#include "light.h"
#include "mini_rt.h"
#include "scene.h"

static double	get_light_ratio(t_parser *parser, t_list *node)
{
	char	*token;
	double	ratio;

	token = (char *)node->content;
	if (!ft_isfloat(token))
		parser_error("parse_light", "ratio must be numeric", parser);
	ratio = ft_atof(token);
	if (ratio < 0.0 || ratio > 1.0)
		parser_error("parse_light", "ratio out of range [0.0, 1.0]", parser);
	return (ratio);
}

static t_color	get_light_color(t_parser *parser, t_list *node)
{
	char	**arr;
	char	*str;
	double	rgb[3];

	str = (char *)node->content;
	if (str[ft_strlen(str) - 1] == ',')
		parser_error("parse_light", "invalid RGB format", parser);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("get_light_color", strerror(errno), parser->scene);
	}
	validate_rgb(arr, parser);
	rgb[0] = ft_atof(arr[0]) / 255.0;
	rgb[1] = ft_atof(arr[1]) / 255.0;
	rgb[2] = ft_atof(arr[2]) / 255.0;
	ft_split_free(arr);
	return (color(rgb[0], rgb[1], rgb[2]));
}

static t_vector	get_light_vector(t_parser *parser, t_list *node)
{
	char		**arr;
	char		*str;
	double		xyz[3];

	str = (char *)node->content;
	if (str[ft_strlen(str) - 1] == ',')
		parser_error("parse_light", "invalid vector format", parser);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_light", strerror(errno), parser->scene);
	}
	validate_vector(arr, parser, xyz);
	ft_split_free(arr);
	return (vector(xyz[0], xyz[1], xyz[2]));
}

static void	validate_light_argc(t_parser *parser)
{
	if (parser->scene->light != NULL)
		parser_error("parse_light", "multiple declarations", parser);
	if (ft_lstsize(parser->list) != 4)
		parser_error("parse_light", "invalid format", parser);
}

void	parse_light(t_parser *parser)
{
	double		ratio;
	t_color		color;
	t_list		*node;
	t_vector	pos;

	validate_light_argc(parser);
	node = parser->list->next;
	pos = get_light_vector(parser, node);
	node = node->next;
	ratio = get_light_ratio(parser, node);
	node = node->next;
	color = get_light_color(parser, node);
	parser->scene->light = new_light(pos, color, ratio);
	if (parser->scene->light == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_light", strerror(errno), parser->scene);
	}
}
