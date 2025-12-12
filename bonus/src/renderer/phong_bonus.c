/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:07:55 by cwon              #+#    #+#             */
/*   Updated: 2025/12/12 14:11:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "light_bonus.h"
#include "camera_bonus.h"

static t_color	phong_ambient(const t_hit *h)
{
	return (scale_color(h->color, KA));
}

static t_color	phong_diffuse(const t_hit *h, const t_light *l)
{
	double		diff;
	t_vector	v;

	v = normalize(subtract(l->pos, h->point));
	diff = fmax(0.0, dot(h->normal, v));
	diff *= KD * l->brightness;
	return (scale_color(h->color, diff));
}

static t_color	phong_specular(const t_hit *h, const t_light *l,
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
	spec = KS * pow(rv, SHININESS) * l->brightness;
	return (scale_color(l->color, spec));
}

t_color	phong_shade(const t_hit *h, const t_light *l, const t_camera *c)
{
	t_color	amb;
	t_color	diff;
	t_color	out;
	t_color	spec;

	amb = phong_ambient(h);
	diff = phong_diffuse(h, l);
	spec = phong_specular(h, l, c);
	out = add_color(amb, diff);
	out = add_color(out, spec);
	return (out);
}
