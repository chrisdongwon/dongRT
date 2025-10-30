/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:44 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 13:39:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <math.h>
#include <stdlib.h>
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

static t_vector	get_vector(t_parser *parser, t_list *node, bool normalized)
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

static void	set_camera(t_parser *p, t_vector pos, t_vector dir, double fov)
{
	p->scene->cam->aspect = (double)WIN_WIDTH / (double)WIN_HEIGHT;
	p->scene->cam->basis = basis(dir, vector(0.0, 1.0, 0.0));
	p->scene->cam->fov = fov;
	p->scene->cam->pos = pos;
	p->scene->cam->scale = tan((p->scene->cam->fov * M_PI / 180.0) / 2.0);
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
	pos = get_vector(parser, node, false);
	node = node->next;
	dir = get_vector(parser, node, true);
	node = node->next;
	fov = get_camera_fov(parser, node);
	parser->scene->cam = malloc(sizeof(t_camera));
	if (parser->scene->cam == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_camera", strerror(errno), parser->scene);
	}
	set_camera(parser, pos, dir, fov);
}
