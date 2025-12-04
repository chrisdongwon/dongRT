/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:54:55 by cwon              #+#    #+#             */
/*   Updated: 2025/12/04 14:17:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "object_bonus.h"
#include "paraboloid_bonus.h"
#include "quadratic_bonus.h"
#include "ray_bonus.h"

static t_quadratic	solve_intersection(const t_ray *r, const t_paraboloid *p,
const t_vector *v)
{
	double		abc[3];
	t_vector	d_perp;
	t_vector	v_perp;

	d_perp = perp(r->dir, p->normal);
	v_perp = perp(*v, p->normal);
	abc[0] = dot(d_perp, d_perp);
	abc[1] = 2.0 * dot(v_perp, d_perp) - p->k * dot(r->dir, p->normal);
	abc[2] = dot(v_perp, v_perp) - p->k * dot(*v, p->normal);
	return (solve_quadratic(abc));
}

static void	hit_cap(const t_ray *r, const t_paraboloid *p, const t_vector *v,
t_hit *h)
{
	double		len;
	double		proj;
	double		radius;
	t_vector	center;

	if (h->is_hit)
		return ;
	proj = dot(r->dir, p->normal);
	if (fabs(proj) < EPSILON)
		return ;
	h->t = (p->height - dot(*v, p->normal)) / proj;
	if (h->t < EPSILON)
		return ;
	h->point = add(r->origin, scale(h->t, r->dir));
	center = add(p->center, scale(p->height, p->normal));
	radius = sqrt(p->k * p->height);
	len = dot(subtract(h->point, center), subtract(h->point, center));
	if (len > radius * radius)
		return ;
	h->is_hit = true;
	h->normal = p->normal;
}

static void	hit_sides(const t_ray *r, const t_paraboloid *p,
const t_quadratic *q, t_hit *h)
{
	const double	soln[2] = {q->t1, q->t2};
	double			proj;
	int				i;
	t_vector		v;

	i = -1;
	while (++i < 2)
	{
		if (soln[i] < EPSILON)
			continue ;
		h->point = add(r->origin, scale(soln[i], r->dir));
		v = subtract(h->point, p->center);
		proj = dot(v, p->normal);
		if (0.0 <= proj && proj <= p->height)
		{
			h->is_hit = true;
			h->t = soln[i];
			h->normal = normalize(subtract(scale(2.0, perp(v, p->normal)), \
scale(p->k, p->normal)));
			return ;
		}
	}
}

t_hit	hit_paraboloid(const t_ray *r, const t_object *obj)
{
	t_hit			hit;
	t_paraboloid	*p;
	t_quadratic		q;
	t_vector		v;

	init_hit(&hit);
	p = (t_paraboloid *)obj->ptr;
	v = subtract(r->origin, p->center);
	q = solve_intersection(r, p, &v);
	if (!q.real_roots)
		return (hit);
	hit_sides(r, p, &q, &hit);
	hit_cap(r, p, &v, &hit);
	if (hit.is_hit && dot(hit.normal, r->dir) > 0)
		hit.normal = scale(-1, hit.normal);
	return (hit);
}
