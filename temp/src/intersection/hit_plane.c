/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:42:10 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 11:47:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "plane.h"
#include "ray.h"

bool	hit_plane(const t_plane *plane, const t_ray *ray, t_interval range, \
t_hit *record)
{
	double		t;
	t_vector	v;

	v = vector_subtraction(plane->pos, ray->origin);
	t = dot_product(v, plane->normal) / dot_product(ray->dir, plane->normal);
	if (!in_interval(t, range))
		return (false);
	record->t = t;
	record->point = ray_at(ray, t);
	reorient_normal(ray, plane->normal, record);
	record->color = plane->color;
	return (true);
}
