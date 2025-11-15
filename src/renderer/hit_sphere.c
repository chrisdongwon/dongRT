/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:00:20 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 14:32:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "ray.h"
#include "sphere.h"
#include "quadratic.h"

static void	compute_coefficients(const t_ray *const r, const t_sphere *const s,
const t_vector *const v, double abc[3])
{
	abc[0] = dot(r->dir, r->dir);
	abc[1] = 2.0 * dot(*v, r->dir);
	abc[2] = dot(*v, *v) - s->radius * s->radius;
}

// i am not convinced that this works
t_hit	hit_sphere(const t_ray *const r, const t_sphere *const s)
{
	double		abc[3];
	t_hit		hit;
	t_quadratic	q;
	t_vector	v;

	init_hit(&hit);
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
