/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:46:28 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 13:20:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "scene.h"

static bool	hit_cylinder_objs(const t_list *cylinders, const t_ray *ray, \
t_interval *range, t_hit *record)
{
	bool	hit_anything;
	t_hit	temp;

	hit_anything = false;
	while (cylinders)
	{
		if (hit_cylinder((t_cylinder *)cylinders->content, ray, *range, &temp))
		{
			hit_anything = true;
			*record = temp;
			range->max = temp.t;
		}
		cylinders = cylinders->next;
	}
	return (hit_anything);
}

static bool	hit_plane_objs(const t_list *planes, const t_ray *ray, \
t_interval *range, t_hit *record)
{
	bool	hit_anything;
	t_hit	temp;

	hit_anything = false;
	while (planes)
	{
		if (hit_plane((t_plane *)planes->content, ray, *range, &temp))
		{
			hit_anything = true;
			*record = temp;
			range->max = temp.t;
		}
		planes = planes->next;
	}
	return (hit_anything);
}

static bool	hit_sphere_objs(const t_list *spheres, const t_ray *ray, \
t_interval *range, t_hit *record)
{
	bool	hit_anything;
	t_hit	temp;

	hit_anything = false;
	while (spheres)
	{
		if (hit_sphere((t_sphere *)spheres->content, ray, *range, &temp))
		{
			hit_anything = true;
			*record = temp;
			range->max = temp.t;
		}
		spheres = spheres->next;
	}
	return (hit_anything);
}

bool	hit_scene(const t_scene *scene, const t_ray *ray, t_interval range, \
t_hit *record)
{
	bool	hit_anything;

	hit_anything = false;
	hit_anything |= hit_sphere_objs(scene->spheres, ray, &range, record);
	hit_anything |= hit_plane_objs(scene->planes, ray, &range, record);
	hit_anything |= hit_cylinder_objs(scene->cylinders, ray, &range, record);
	return (hit_anything);
}
