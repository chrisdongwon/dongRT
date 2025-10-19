/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:14:54 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 13:59:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"
#include "scene.h"

t_parser_status	parse_ambient(char **tokens, int count, t_scene *scene, \
t_parser *parser)
{
	double	ratio;
	t_rgb	color;

	if (count != 3 || parser->has_ambient)
		return (PARSER_ERROR);
	if (!parse_double(tokens[1], &ratio) || !ft_isbetween(ratio, 0, 1))
		return (PARSER_ERROR);
	if (!parse_rgb_str(tokens[2], &color))
		return (PARSER_ERROR);
	scene->ambient.ratio = ratio;
	scene->ambient.color = color;
	parser->has_ambient = true;
	return (PARSER_OK);
}

t_parser_status	parse_camera(char **tokens, int count, t_scene *scene, \
t_parser *parser)
{
	double		fov;
	t_vector	dir;
	t_vector	pos;

	if (count != 4 || parser->has_camera)
		return (PARSER_ERROR);
	if (!parse_vector_str(tokens[1], &pos, 0))
		return (PARSER_ERROR);
	if (!parse_vector_str(tokens[2], &dir, 1))
		return (PARSER_ERROR);
	if (!parse_double(tokens[3], &fov) || !ft_isbetween(fov, 0, 180))
		return (PARSER_ERROR);
	scene->camera.fov = fov;
	scene->camera.dir = normalize(dir);
	scene->camera.pos = pos;
	scene->camera.up = vector(0.0, 1.0, 0.0);
	scene->camera.basis.w = normalize(scalar_multiplication(-1.0, \
scene->camera.dir));
	scene->camera.basis.u = normalize(cross_product(scene->camera.up, \
scene->camera.basis.w));
	scene->camera.basis.v = cross_product(scene->camera.basis.w, \
scene->camera.basis.u);
	parser->has_camera = true;
	return (PARSER_OK);
}

t_parser_status	parse_light(char **tokens, int count, t_scene *scene, \
t_parser *parser)
{
	double		brightness;
	t_rgb		color;
	t_vector	pos;

	if (count < 3 || count > 4 || parser->has_light)
		return (PARSER_ERROR);
	if (!parse_vector_str(tokens[1], &pos, 0))
		return (PARSER_ERROR);
	if (!parse_double(tokens[2], &brightness) || \
!ft_isbetween(brightness, 0, 1))
		return (PARSER_ERROR);
	init_rgb(&color, 255, 255, 255);
	if (count == 4 && !parse_rgb_str(tokens[3], &color))
		return (PARSER_ERROR);
	scene->light.pos = pos;
	scene->light.brightness = brightness;
	scene->light.color = color;
	parser->has_light = true;
	return (PARSER_OK);
}
