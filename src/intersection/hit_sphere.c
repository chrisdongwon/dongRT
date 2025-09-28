/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:42:12 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 11:45:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "ray.h"
#include "sphere.h"

bool	hit_sphere(const t_sphere *sphere, const t_ray *ray, t_interval range, \
t_hit *record)
{
	double		t;
	t_quadratic	solution;
	t_vector	v;

	v = vector_subtraction(ray->origin, sphere->center);
	if (!solve_quadratic(dot_product(ray->dir, ray->dir), \
2.0 * dot_product(v, ray->dir), \
dot_product(v, v) - (sphere->diameter * sphere->diameter) / 4.0, &solution))
		return (false);
	t = closest_root_in_range(solution, range);
	if (!in_interval(t, range))
		return (false);
	record->t = t;
	record->point = ray_at(ray, t);
	reorient_normal(ray, scalar_multiplication(2.0 / sphere->diameter, \
vector_subtraction(record->point, sphere->center)), record);
	record->color = sphere->color;
	return (true);
}
