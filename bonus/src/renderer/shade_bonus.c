/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:28:28 by cwon              #+#    #+#             */
/*   Updated: 2025/12/11 14:44:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

#include <math.h>

#include "camera_bonus.h"
#include "light_bonus.h"

static double	compute_projection(const t_hit *h, const t_light *l)
{
	t_vector	dir;

	dir = normalize(subtract(l->pos, h->point));
	return (fmax(0, dot(h->normal, dir)));
}

t_color	lambertian_shade(const t_hit *h, const t_light *l)
{
	double		proj;
	t_color		color;

	proj = compute_projection(h, l);
	color.r = h->color.r * proj * l->brightness;
	color.g = h->color.g * proj * l->brightness;
	color.b = h->color.b * proj * l->brightness;
	return (color);
}

t_color	phong_shade(const t_hit *h, const t_light *l, const t_camera *c)
{
	// STUB
}
