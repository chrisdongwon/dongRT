/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:50:19 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 15:42:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "libft.h"
#include "scene.h"
#include "vector.h"

static double	get_sphere_diameter(t_parser *parser, t_list *node)
{
	char	*token;
	double	dia;

	token = (char *)node->content;
	if (!ft_isfloat(token))
		parser_error("parse_light", "diameter must be numeric", parser);
	dia = ft_atof(token);
	if (dia <= 0.0)
		parser_error("parse_light", "diameter must be positive", parser);
	return (dia);
}

static t_color	get_sphere_color(t_parser *parser, t_list *node)
{
	char	**arr;
	char	*str;
	double	rgb[3];

	str = (char *)node->content;
	if (str[ft_strlen(str) - 1] == ',')
		parser_error("parse_sphere", "invalid RGB format", parser);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("get_sphere_color", strerror(errno), parser->scene);
	}
	validate_rgb(arr, parser);
	rgb[0] = ft_atof(arr[0]) / 255.0;
	rgb[1] = ft_atof(arr[1]) / 255.0;
	rgb[2] = ft_atof(arr[2]) / 255.0;
	ft_split_free(arr);
	return (color(rgb[0], rgb[1], rgb[2]));
}

static t_vector	get_sphere_vector(t_parser *parser, t_list *node)
{
	char	**arr;
	char	*str;
	double	xyz[3];

	str = (char *)node->content;
	if (str[ft_strlen(str) - 1] == ',')
		parser_error("parse_sphere", "invalid vector format", parser);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(parser);
		mini_rt_error("parse_sphere", strerror(errno), parser->scene);
	}
	validate_vector(arr, parser, xyz);
	ft_split_free(arr);
	return (vector(xyz[0], xyz[1], xyz[2]));
}

static void	validate_sphere_argc(t_parser *parser)
{
	if (ft_lstsize(parser->list) != 4)
		parser_error("parse_sphere", "invalid format", parser);
}

void	parse_sphere(t_parser *parser)
{
	double		diameter;
	t_color		color;
	t_list		*node;
	t_vector	center;

	validate_sphere_argc(parser);
	node = parser->list->next;
	center = get_sphere_vector(parser, node);
	node = node->next;
	diameter = get_sphere_diameter(parser, node);
	node = node->next;
	color = get_sphere_color(parser, node);
	// memory allocate sphere
	// make linked list node
	// push into linked list
}
