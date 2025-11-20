/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:00:20 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 15:34:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "object.h"
#include "quadratic.h"
#include "ray.h"
#include "sphere.h"

static void	compute_coefficients(const t_ray *r, const t_sphere *s,
const t_vector *v, double abc[3])
{
	abc[0] = dot(r->dir, r->dir);
	abc[1] = 2.0 * dot(*v, r->dir);
	abc[2] = dot(*v, *v) - s->radius * s->radius;
}

t_hit	hit_sphere(const t_ray *r, const t_object *obj)
{
	double		abc[3];
	t_hit		hit;
	t_quadratic	q;
	t_vector	v;
	t_sphere	*s;

	init_hit(&hit);
	s = (t_sphere *)obj->ptr;
	v = subtract(r->origin, s->center);
	compute_coefficients(r, s, &v, abc);
	q = solve_quadratic(abc);
	if (!q.real_roots)
		return (hit);
	hit.t = min_positive_root(&q);
	if (hit.t < 0)
		return (hit);
	hit.is_hit = true;
	hit.point = add(r->origin, scale(hit.t, r->dir));
	hit.normal = normalize(subtract(hit.point, s->center));
	return (hit);
}
