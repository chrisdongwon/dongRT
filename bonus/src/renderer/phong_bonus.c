/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:07:55 by cwon              #+#    #+#             */
/*   Updated: 2026/02/28 16:45:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "light_bonus.h"
#include "camera_bonus.h"
#include "object_bonus.h"

static t_color	phong_ambient(t_color color)
{
	return (scale_color(color, KA));
}

static t_color	phong_diffuse(const t_hit *h, const t_light *l, t_color color)
{
	double		diff;
	t_vector	u;

	u = normalize(subtract(l->pos, h->point));
	diff = fmax(0.0, dot(h->normal, u));
	diff *= KD;
	return (scale_color(color, diff));
}

static t_color	phong_specular(const t_hit *h, const t_light *l, \
const t_camera *c)
{
	double		rv;
	double		spec;
	t_vector	u;
	t_vector	v;
	t_vector	w;

	u = normalize(subtract(l->pos, h->point));
	w = normalize(subtract(c->pos, h->point));
	if (dot(h->normal, u) <= 0)
		return ((t_color){0, 0, 0});
	v = subtract(scale(2.0 * dot(h->normal, u), h->normal), u);
	rv = dot(v, w);
	if (rv <= 0)
		return ((t_color){0, 0, 0});
	spec = KS * pow(rv, SHININESS);
	return (scale_color(l->color, spec));
}

t_color	phong_shade(const t_hit *h, const t_light *l, const t_camera *c, \
t_color color)
{
	t_color	amb;
	t_color	diff;
	t_color	spec;
	t_color	light_part;
	t_color	out;

	amb = phong_ambient(color);
	diff = phong_diffuse(h, l, color);
	spec = phong_specular(h, l, c);
	light_part = add_color(diff, spec);
	light_part = scale_color(light_part, l->brightness);
	out = add_color(amb, light_part);
	return (out);
}
