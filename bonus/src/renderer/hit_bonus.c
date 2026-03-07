/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:35:44 by cwon              #+#    #+#             */
/*   Updated: 2026/03/07 16:31:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "libft.h"
#include "object_bonus.h"
#include "ray_bonus.h"
#include "scene_bonus.h"

static bool	intersect(const t_object *obj, const t_ray *ray, double *t)
{
	t_hit	hit;

	if (!obj || !ray || !t)
		return (false);
	if (obj->type == CYLINDER)
		hit = hit_cylinder(ray, obj);
	else if (obj->type == PARABOLOID)
		hit = hit_paraboloid(ray, obj);
	else if (obj->type == SPHERE)
		hit = hit_sphere(ray, obj);
	else if (obj->type == PLANE)
		hit = hit_plane(ray, obj);
	else
		return (false);
	if (!hit.is_hit)
		return (false);
	*t = hit.t;
	return (true);
}

bool	in_shadow(const t_hit *h, t_vector light_pos, t_list *objects)
{
	double		light_dist;
	double		t;
	t_object	*obj;
	t_ray		shadow_ray;
	t_vector	to_light;

	to_light = subtract(light_pos, h->point);
	light_dist = norm(to_light);
	shadow_ray.origin = add(h->point, scale(1e-4, h->normal));
	shadow_ray.dir = normalize(to_light);
	while (objects)
	{
		obj = (t_object *)objects->content;
		if (intersect(obj, &shadow_ray, &t) && (t > 0 && t < light_dist))
			return (true);
		objects = objects->next;
	}
	return (false);
}

t_hit	hit_scene(const t_scene *s, const t_ray *r)
{
	t_hit		hit;
	t_hit		temp;
	t_list		*node;
	t_object	*obj;

	init_hit(&hit);
	node = s->objects;
	while (node != NULL)
	{
		obj = (t_object *)node->content;
		temp = obj->hit_fn(r, obj);
		temp.obj = obj;
		if (temp.is_hit && temp.t < hit.t)
			hit = temp;
		node = node->next;
	}
	return (hit);
}

void	init_hit(t_hit *h)
{
	ft_memset(h, 0, sizeof(*h));
	h->t = INFINITY;
}
