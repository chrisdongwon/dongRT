/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:49:44 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:43:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "cylinder_bonus.h"
#include "object_bonus.h"
#include "quadratic_bonus.h"
#include "ray_bonus.h"

static t_quadratic	solve_intersection(const t_ray *r, const t_cylinder *c,
const t_vector *v)
{
	double		abc[3];
	t_vector	d_perp;
	t_vector	v_perp;

	d_perp = perp(r->dir, c->axis);
	v_perp = perp(*v, c->axis);
	abc[0] = dot(d_perp, d_perp);
	abc[1] = 2.0 * dot(d_perp, v_perp);
	abc[2] = dot(v_perp, v_perp) - (c->radius * c->radius);
	return (solve_quadratic(abc));
}

static void	hit_sides(const t_ray *r, const t_cylinder *c,
const t_quadratic *q, t_hit *h)
{
	const double	soln[2] = {q->t1, q->t2};
	double			height;
	int				i;
	t_vector		point;
	t_vector		v;

	i = -1;
	while (++i < 2)
	{
		if (soln[i] < EPSILON)
			continue ;
		point = add(r->origin, scale(soln[i], r->dir));
		height = dot(subtract(point, c->center), c->axis);
		if (0.0 <= height && height <= c->height)
		{
			v = add(c->center, scale(height, c->axis));
			h->is_hit = true;
			h->t = soln[i];
			h->point = point;
			h->normal = normalize(subtract(point, v));
			return ;
		}
	}
}

static void	hit_bottom_cap(const t_ray *r, const t_cylinder *c,
const t_vector *v, t_hit *h)
{
	double	length;
	double	proj;

	if (h->is_hit)
		return ;
	proj = dot(r->dir, c->axis);
	if (fabs(proj) > EPSILON)
	{
		h->t = -dot(*v, c->axis) / proj;
		if (h->t > EPSILON)
		{
			h->point = add(r->origin, scale(h->t, r->dir));
			length = norm(subtract(h->point, c->center));
			if (length * length <= c->radius * c->radius)
			{
				h->is_hit = true;
				h->normal = scale(-1, c->axis);
			}
		}
	}
}

static void	hit_top_cap(const t_ray *r, const t_cylinder *c,
const t_vector *v, t_hit *h)
{
	double		length;
	double		proj;
	t_vector	center;

	if (h->is_hit)
		return ;
	proj = dot(r->dir, c->axis);
	if (fabs(proj) > EPSILON)
	{
		h->t = (c->height - dot(*v, c->axis)) / proj;
		if (h->t > EPSILON)
		{
			center = add(c->center, scale(c->height, c->axis));
			h->point = add(r->origin, scale(h->t, r->dir));
			length = norm(subtract(h->point, center));
			if (length * length <= c->radius * c->radius)
			{
				h->is_hit = true;
				h->normal = c->axis;
			}
		}
	}
}

t_hit	hit_cylinder(const t_ray *r, const t_object *obj)
{
	t_cylinder	*c;
	t_hit		hit;
	t_quadratic	q;
	t_vector	v;

	init_hit(&hit);
	c = (t_cylinder *)obj->ptr;
	v = subtract(r->origin, c->center);
	q = solve_intersection(r, c, &v);
	if (!q.real_roots)
		return (hit);
	hit_sides(r, c, &q, &hit);
	hit_bottom_cap(r, c, &v, &hit);
	hit_top_cap(r, c, &v, &hit);
	return (hit);
}
