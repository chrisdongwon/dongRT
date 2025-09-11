/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:17:44 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:10:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>

#include "libft.h"
#include "scene.h"

t_parser_status	parse_sphere(char **tokens, int count, t_scene *scene)
{
	t_sphere	*sphere;
	t_list		*node;

	if (count != 4)
		return (PARSER_ERROR);
	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (PARSER_ERROR);
	if (!parse_vector_str(tokens[1], &sphere->center, 0) || \
!parse_double(tokens[2], &sphere->diameter) || sphere->diameter <= 0 || \
!parse_rgb_str(tokens[3], &sphere->color))
	{
		free(sphere);
		return (PARSER_ERROR);
	}
	node = ft_lstnew(sphere);
	if (node == NULL)
	{
		free(sphere);
		return (PARSER_ERROR);
	}
	ft_lstadd_back(&scene->spheres, node);
	return (PARSER_OK);
}

t_parser_status	parse_plane(char **tokens, int count, t_scene *scene)
{
	t_plane	*plane;
	t_list	*node;

	if (count != 4)
		return (PARSER_ERROR);
	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (PARSER_ERROR);
	if (!parse_vector_str(tokens[1], &plane->pos, 0) || \
!parse_vector_str(tokens[2], &plane->normal, 1) || \
!parse_rgb_str(tokens[3], &plane->color))
	{
		free(plane);
		return (PARSER_ERROR);
	}
	node = ft_lstnew(plane);
	if (node == NULL)
	{
		free(plane);
		return (PARSER_ERROR);
	}
	ft_lstadd_back(&scene->planes, node);
	return (PARSER_OK);
}

t_parser_status	parse_cylinder(char **tokens, int count, t_scene *scene)
{
	t_cylinder	*cyl;
	t_list		*node;

	if (count != 6)
		return (PARSER_ERROR);
	cyl = malloc(sizeof(t_cylinder));
	if (cyl == NULL)
		return (PARSER_ERROR);
	if (!parse_vector_str(tokens[1], &cyl->pos, 0) || \
!parse_vector_str(tokens[2], &cyl->dir, 1) || \
!parse_double(tokens[3], &cyl->diameter) || cyl->diameter <= 0 || \
!parse_double(tokens[4], &cyl->height) || cyl->height <= 0 || \
!parse_rgb_str(tokens[5], &cyl->color))
	{
		free(cyl);
		return (PARSER_ERROR);
	}
	node = ft_lstnew(cyl);
	if (node == NULL)
	{
		free(cyl);
		return (PARSER_ERROR);
	}
	ft_lstadd_back(&scene->cylinders, node);
	return (PARSER_OK);
}
