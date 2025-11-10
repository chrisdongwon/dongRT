/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:52:00 by cwon              #+#    #+#             */
/*   Updated: 2025/11/10 15:37:41 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include <math.h>

#include "libft.h"
#include "object.h"
#include "scene.h"

bool	scene_hit(t_scene *scene, t_ray ray, t_hit *closest_hit)
{
	t_hit		temp;
	t_list		*node;
	t_object	*obj;

	closest_hit->t = INFINITY;
	closest_hit->hit = false;
	node = scene->objects;
	while (node)
	{
		obj = (t_object *)node->content;
		if (obj->hit_fn(obj, ray, &temp) && temp.t < closest_hit->t)
			*closest_hit = temp;
		node = node->next;
	}
	return (closest_hit->hit);
}
