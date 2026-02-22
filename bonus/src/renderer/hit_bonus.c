/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:35:44 by cwon              #+#    #+#             */
/*   Updated: 2026/02/22 12:58:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "libft.h"
#include "object_bonus.h"
#include "scene_bonus.h"

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
