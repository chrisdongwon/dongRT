/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:42:14 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 13:21:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "cylinder.h"
#include "ray.h"

static bool	cylinder_quadratic(const t_cylinder *cyl, const t_ray *ray, \
t_quadratic *solution)
{
	double		a;
	double		b;
	double		c;
	t_vector	d;
	t_vector	v;

	v = vector_subtraction(ray->origin, cyl->pos);
	d = ray->dir;
	a = dot_product(d, d) - pow(dot_product(d, cyl->dir), 2);
	b = 2.0 * \
(dot_product(d, v) - dot_product(d, cyl->dir) * dot_product(v, cyl->dir));
	c = dot_product(v, v) - pow(dot_product(v, cyl->dir), 2) - \
pow(cyl->diameter / 2.0, 2);
	return (solve_quadratic(a, b, c, solution));
}

static bool	is_within_height(const t_cylinder *cyl, t_vector p)
{
	double		height;
	t_vector	axis_vec;

	axis_vec = vector_subtraction(p, cyl->pos);
	height = dot_product(axis_vec, cyl->dir);
	return (height >= 0 && height <= cyl->height);
}

static t_vector	cylinder_normal(const t_cylinder *cyl, t_vector p)
{
	t_vector	proj;
	t_vector	v;

	v = vector_subtraction(p, cyl->pos);
	proj = vector_projection(v, cyl->dir);
	return (vector_subtraction(v, proj));
}

// at the moment, this is a hollow cylinder?
bool	hit_cylinder(const t_cylinder *cyl, const t_ray *ray, \
t_interval range, t_hit *record)
{
	double		t;
	t_quadratic	solution;
	t_vector	n;
	t_vector	p;

	if (!cylinder_quadratic(cyl, ray, &solution))
		return (false);
	t = closest_root_in_range(solution, range);
	if (!in_interval(t, range))
		return (false);
	p = ray_at(ray, t);
	if (!within_cylinder_height(cyl, p))
		return (false);
	record->t = t;
	record->point = p;
	n = cylinder_normal(cyl, p);
	reorient_normal(ray, n, record);
	record->color = cyl->color;
	return (true);
}
