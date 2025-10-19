/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:01:49 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 14:38:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_reflect(const t_ray *incoming, t_vector normal, t_vector hit_point)
{
	t_vector	origin_offset;
	t_vector	reflected_dir;

	origin_offset = vector_add(hit_point, vector_scale(RAY_EPS, normal));
	reflected_dir = vector_reflect(incoming->dir, normal);
	return (ray(origin_offset, reflected_dir));
}

t_ray	ray(t_vector origin, t_vector direction)
{
	t_ray	r;

	r.origin = origin;
	r.dir = normalize(direction);
	return (r);
}

t_vector	ray_at(const t_ray *r, double t)
{
	return (vector_add(r->origin, vector_scale(t, r->dir)));
}

t_vector	ray_project_point(const t_ray *r, t_vector point)
{
	double		t;
	t_vector	v;

	v = vector_sub(point, r->origin);
	t = dot_prod(v, r->dir);
	return (ray_at(r, t));
}
