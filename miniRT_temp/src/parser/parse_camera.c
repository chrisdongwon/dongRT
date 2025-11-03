/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:44 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 09:39:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <string.h>

#include "camera.h"
#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

static double	get_camera_fov(t_parser *parser, t_list *node)
{
	char	*token;
	double	ratio;

	token = (char *)node->content;
	if (!ft_isfloat(token))
		parser_error("parse_camera", "ratio must be numeric", parser);
	ratio = ft_atof(token);
	if (ratio < 0.0 || ratio > 180.0)
		parser_error("parse_camera", "ratio out of range [0.0, 180.0]", parser);
	return (ratio);
}

static t_vector	get_cam_vector(t_parser *parser, t_list *node, bool normalized)
{
	char		**arr;
	char		*str;
	double		xyz[3];
	t_vector	v;

	str = (char *)node->content;
	if (str[ft_strlen(str) - 1] == ',')
		parser_error("parse_camera", "invalid vector format", parser);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_camera", strerror(errno), parser->scene);
	}
	validate_vector(arr, parser, xyz);
	ft_split_free(arr);
	v = vector(xyz[0], xyz[1], xyz[2]);
	if (normalized && (vector_norm(v) != 1.0))
		parser_error("parse_camera", "orientation must be normalized", parser);
	return (v);
}

static void	validate_camera_argc(t_parser *parser)
{
	if (parser->scene->cam != NULL)
		parser_error("parse_camera", "multiple declarations", parser);
	if (ft_lstsize(parser->list) != 4)
		parser_error("parse_camera", "invalid format", parser);
}

void	parse_camera(t_parser *parser)
{
	double		fov;
	t_list		*node;
	t_vector	dir;
	t_vector	pos;

	validate_camera_argc(parser);
	node = parser->list->next;
	pos = get_cam_vector(parser, node, false);
	node = node->next;
	dir = get_cam_vector(parser, node, true);
	node = node->next;
	fov = get_camera_fov(parser, node);
	parser->scene->cam = new_camera(pos, dir, fov);
	if (parser->scene->cam == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_camera", strerror(errno), parser->scene);
	}
}
