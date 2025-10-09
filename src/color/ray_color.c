/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:44:05 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 14:27:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

#include <math.h>

#include "hit.h"
#include "ray.h"
#include "scene.h"

static t_color	background_color(const t_ray *ray)
{
	double		t;
	t_vector	unit_dir;

	unit_dir = normalize(ray->dir);
	t = 0.5 * (unit_dir.y + 1.0);
	return (color_add(color_multiply(color(1.0, 1.0, 1.0), 1.0 - t), \
color_multiply(color(0.5, 0.7, 1.0), t)));
}

static t_color	shade_hit(const t_hit *record, const t_scene *scene)
{
	double		intensity;
	t_color		ambient;
	t_color		surface_color;
	t_vector	light_dir;

	surface_color = rgb_to_color(record->color);
	ambient = color_multiply(rgb_to_color(scene->ambient.color), \
scene->ambient.ratio);
	light_dir = normalize(vector_subtraction(scene->light.pos, record->point));
	intensity = fmax(0.0, dot_product(record->normal, light_dir));
	surface_color = color_hadamard(surface_color, \
color_add(ambient, color_multiply(rgb_to_color(scene->light.color), \
scene->light.brightness * intensity)));
	return (color_clamp(surface_color));
}

t_color	ray_color(const t_ray *ray, const t_scene *scene)
{
	t_hit		record;
	t_interval	range;

	range.min = 1e-4;
	range.max = INFINITY;
	if (hit_scene(scene, ray, range, &record))
		return (shade_hit(&record, scene));
	return (background_color(ray));
}
