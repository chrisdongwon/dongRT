/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:54:55 by cwon              #+#    #+#             */
/*   Updated: 2025/12/03 15:38:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include "object_bonus.h"
#include "paraboloid_bonus.h"
#include "quadratic_bonus.h"
#include "ray_bonus.h"

static bool	is_finite_height(const t_ray *r, const t_paraboloid *p, double t)
{
	double		height;
	t_vector	hit;

	hit = add(r->origin, scale(t, r->dir));
	height = dot(subtract(hit, p->center), p->normal);
	return (height >= 0.0 && height <= p->height);
}

static t_quadratic	solve_intersection(const t_ray *r, const t_paraboloid *p)
{
	double		abc[3];
	t_vector	d_perp;
	t_vector	v_perp;
	t_vector	v;

	v = subtract(r->origin, p->center);
	d_perp = perp(r->dir, p->normal);
	v_perp = perp(v, p->normal);
	abc[0] = dot(d_perp, d_perp);
	abc[1] = 2.0 * dot(v_perp, d_perp) - p->k * dot(r->dir, p->normal);
	abc[3] = dot(v_perp, v_perp) - p->k * dot(v, p->normal);
	return (solve_quadratic(abc));
}

static t_vector	paraboloid_normal(const t_paraboloid *p, t_vector hit_point)
{
	t_vector	n;
	t_vector	v_perp;
	t_vector	v;

	v = subtract(hit_point, p->center);
	v_perp = perp(v, p->normal);
	n = subtract(scale(2.0, v_perp), scale(p->k, p->normal));
	return (normalize(n));
}

t_hit	hit_paraboloid(const t_ray *r, const t_object *obj)
{
	t_hit			hit;
	t_paraboloid	*p;
	t_quadratic		q;

	init_hit(&hit);
	p = (t_paraboloid *)obj->ptr;
	q = solve_intersection(r, p);
	if (!q.real_roots)
		return (hit);
	hit.t = min_positive_root(&q);
	if (hit.t < EPSILON || !is_finite_height(r, p, hit.t))
		return (hit);
	hit.is_hit = true;
	hit.point = add(r->origin, scale(hit.t, r->dir));
	hit.normal = paraboloid_normal(p, hit.point);
	return (hit);
}
