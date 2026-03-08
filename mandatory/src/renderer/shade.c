/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:28:28 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 16:10:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include <math.h>

#include "ambient.h"
#include "light.h"
#include "object.h"
#include "ray.h"
#include "scene.h"

static bool	in_shadow(const t_hit *h, const t_scene *s)
{
	double		dist;
	t_hit		hit;
	t_ray		shadow;
	t_vector	to_light;

	to_light = subtract(s->light->pos, h->point);
	dist = norm(to_light);
	shadow.origin = add(h->point, scale(1e-6, h->normal));
	shadow.dir = normalize(to_light);
	hit = hit_scene(s, &shadow);
	return (hit.is_hit && hit.t < dist);
}

t_color	lambertian_shade(const t_hit *h, const t_scene *s)
{
	double		diff;
	t_color		result;
	t_vector	light_dir;

	result = scale_color(h->obj->color, s->ambient->ratio);
	if (!in_shadow(h, s))
	{
		light_dir = normalize(subtract(s->light->pos, h->point));
		diff = fmax(0.0, dot(h->normal, light_dir));
		diff *= s->light->brightness;
		result = add_color(result, scale_color(h->obj->color, diff));
	}
	return (result);
}
