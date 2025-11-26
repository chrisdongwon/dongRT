/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:51:53 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:43:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include "object_bonus.h"
#include "plane_bonus.h"
#include "ray_bonus.h"

t_hit	hit_plane(const t_ray *r, const t_object *obj)
{
	double		proj;
	t_hit		hit;
	t_plane		*p;
	t_vector	v;

	init_hit(&hit);
	p = (t_plane *)obj->ptr;
	proj = dot(r->dir, p->normal);
	if (proj == 0.0)
		return (hit);
	v = subtract(p->point, r->origin);
	hit.t = dot(v, p->normal) / proj;
	if (hit.t < 0)
		return (hit);
	hit.is_hit = true;
	hit.point = add(r->origin, scale(hit.t, r->dir));
	hit.normal = p->normal;
	return (hit);
}
