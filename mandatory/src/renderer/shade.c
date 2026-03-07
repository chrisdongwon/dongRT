/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:28:28 by cwon              #+#    #+#             */
/*   Updated: 2026/03/07 16:47:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include <math.h>

#include "light.h"
#include "scene.h"

static double	compute_projection(const t_hit *h, const t_light *l)
{
	t_vector	dir;

	dir = normalize(subtract(l->pos, h->point));
	return (fmax(0, dot(h->normal, dir)));
}

t_color	lambertian_shade(const t_hit *h, const t_scene *s)
{
	double		proj;
	t_color		color;

	color = (t_color){0, 0, 0};
	if (!in_shadow(h, s->light->pos, s->objects))
	{
		proj = compute_projection(h, s->light);
		color.r = h->color.r * proj * s->light->brightness;
		color.g = h->color.g * proj * s->light->brightness;
		color.b = h->color.b * proj * s->light->brightness;
	}
	return (color);
}
