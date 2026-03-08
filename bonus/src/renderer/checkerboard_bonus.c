/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:37 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 13:44:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"

#include <math.h>
#include <stdlib.h>

#include "hit_bonus.h"
#include "object_bonus.h"
#include "plane_bonus.h"

t_color	checkerboard(const t_hit *hit)
{
	int		x;
	int		y;
	t_plane	*p;

	p = (t_plane *)hit->obj->ptr;
	x = floor(dot(subtract(hit->point, p->point), p->u));
	y = floor(dot(subtract(hit->point, p->point), p->v));
	if ((abs(x + y) % 2))
		return (invert_color(hit->obj->color));
	return (hit->obj->color);
}
