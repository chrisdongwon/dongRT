/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:07:55 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 13:50:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"

#include <math.h>

#include "camera_bonus.h"
#include "hit_bonus.h"
#include "libft.h"
#include "light_bonus.h"
#include "object_bonus.h"
#include "scene_bonus.h"
#include "spotlight_bonus.h"

static t_color	phong_ambient(t_color color)
{
	return (scale_color(color, KA));
}

t_color	phong_diffuse(const t_hit *h, const t_light *l, t_color color)
{
	double		diff;
	t_vector	u;

	u = normalize(subtract(l->pos, h->point));
	diff = fmax(0.0, dot(h->normal, u));
	diff *= KD;
	return (scale_color(color, diff));
}

t_color	phong_shade(const t_hit *h, const t_scene *s, t_color color)
{
	t_color		total;
	t_list		*node;
	t_spotlight	*sp;

	total = phong_ambient(color);
	if (s->light && !in_shadow(h, s->light->pos, s->objects))
		total = add_color(total, contribute_light(h, s, color));
	node = s->spotlights;
	while (node)
	{
		sp = (t_spotlight *)(node->content);
		if (!in_shadow(h, sp->pos, s->objects) && in_spotlight(h, sp))
			total = add_color(total, contribute_spot(h, sp, s->camera, color));
		node = node->next;
	}
	return (total);
}

t_color	phong_specular(const t_hit *h, const t_light *l, const t_camera *c)
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
