/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:26:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 15:35:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "cylinder.h"
#include "libft.h"
#include "object.h"
#include "plane.h"
#include "sphere.h"

void	parse_cylinder(t_parser *p)
{
	t_color		color;
	t_cylinder	*cylinder;
	t_cylinder	temp;

	check_token_count(p, 6);
	temp.center = get_vector(p, 1, false);
	temp.dir = get_vector(p, 2, true);
	temp.radius = get_float(p, 3) / 2.0;
	temp.height = get_float(p, 4);
	color = get_color(p, 5);
	cylinder = parser_malloc(p, sizeof(t_cylinder));
	*cylinder = temp;
	append_object(p, cylinder, CYLINDER, color);
}

void	parse_plane(t_parser *p)
{
	t_color	color;
	t_plane	*plane;
	t_plane	temp;

	check_token_count(p, 4);
	temp.point = get_vector(p, 1, false);
	temp.normal = get_vector(p, 2, true);
	color = get_color(p, 3);
	plane = parser_malloc(p, sizeof(t_plane));
	*plane = temp;
	append_object(p, plane, PLANE, color);
}

void	parse_sphere(t_parser *p)
{
	t_color		color;
	t_sphere	*sphere;
	t_sphere	temp;

	check_token_count(p, 4);
	temp.center = get_vector(p, 1, false);
	temp.radius = get_float(p, 2) / 2.0;
	color = get_color(p, 3);
	sphere = parser_malloc(p, sizeof(t_sphere));
	*sphere = temp;
	append_object(p, sphere, SPHERE, color);
}
