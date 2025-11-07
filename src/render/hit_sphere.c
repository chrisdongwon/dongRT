/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:17:44 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 15:18:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "sphere.h"
#include "ray.h"

bool	hit_sphere(t_sphere *s, t_ray r, t_hit *rec)
{
	t_vector oc = sub(r.origin, s->center);
	double a = dot(r.dir, r.dir);
	double b = 2.0 * dot(oc, r.dir);
	double c = dot(oc, oc) - s->radius * s->radius;
	double disc = b * b - 4 * a * c;
	if (disc < 0)
		return (false);
	double t = (-b - sqrt(disc)) / (2.0 * a);
	if (t < 0)
		t = (-b + sqrt(disc)) / (2.0 * a);
	if (t < 0)
		return (false);
	rec->t = t;
	rec->point = add(r.origin, mul(r.dir, t));
	rec->normal = normalize(sub(rec->point, s->center));
	rec->color = s->color;
	rec->hit = true;
	return (true);
}
