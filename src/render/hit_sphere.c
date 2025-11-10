/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:55:38 by cwon              #+#    #+#             */
/*   Updated: 2025/11/10 14:54:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "object.h"
#include "quadratic.h"
#include "sphere.h"

bool	hit_sphere(t_object *obj, t_ray *r, t_hit *h)
{
	double		abc[3];
	t_sphere	*s;
	t_vector	v;

	s = (t_sphere *)obj->ptr;	
	v = subtract(r->origin, s->center);
	abc[0] = dot(r->dir, r->dir);
	abc[1] = 2.0 * dot(v, r->dir);
	abc[2] = dot(v, v) - s->radius * s->radius;
	if (!solve_quadratic(abc, &h->t))
		return (false);
	h->point = add(r->origin, scale(h->t, r->dir));
	h->normal = normalize(subtract(h->point, s->center));
	h->color = obj->color;
	h->obj = obj;
	h->hit = true;
	return (true);
}
