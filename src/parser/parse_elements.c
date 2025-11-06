/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:09:44 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 13:33:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>

#include "ambient.h"
#include "camera.h"
#include "light.h"
#include "mini_rt.h"
#include "scene.h"

void	parse_ambient(t_parser *p)
{
	check_multiple_declarations(p, p->scene->ambient);
	check_token_count(p, 3);
	p->scene->ambient = (t_ambient *)parser_malloc(p, sizeof(t_ambient));
	p->scene->ambient->ratio = get_ratio(p, 1);
	p->scene->ambient->color = get_color(p, 2);
}

void	parse_camera(t_parser *p)
{
	check_multiple_declarations(p, p->scene->camera);
	check_token_count(p, 4);
	p->scene->camera = (t_camera *)parser_malloc(p, sizeof(t_camera));
	p->scene->camera->pos = get_vector(p, 1, false);
	p->scene->camera->dir = get_vector(p, 2, true);
	p->scene->camera->fov = get_fov(p, 3);
}

void	parse_light(t_parser *p)
{
	check_multiple_declarations(p, p->scene->light);
	check_token_count(p, 4);
	p->scene->light = (t_light *)parser_malloc(p, sizeof(t_light));
	p->scene->light->pos = get_vector(p, 1, false);
	p->scene->light->brightness = get_ratio(p, 2);
	p->scene->light->color = get_color(p, 3);
}
