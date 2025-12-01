/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:54:55 by cwon              #+#    #+#             */
/*   Updated: 2025/12/01 09:15:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include "object_bonus.h"
#include "paraboloid_bonus.h"
#include "quadratic_bonus.h"
#include "ray_bonus.h"

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
	// STUB
	return (hit);
}
