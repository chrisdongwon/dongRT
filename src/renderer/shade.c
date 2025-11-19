/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:28:28 by cwon              #+#    #+#             */
/*   Updated: 2025/11/18 15:09:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include <math.h>

#include <stdio.h>

#include "light.h"

static double	compute_projection(const t_hit *const h, const t_light *const l)
{
	t_vector	dir;

	dir = normalize(subtract(l->pos, h->point));
	return (fmax(0, dot(h->normal, dir)));
}

t_color	lambertian_shade(const t_hit *const h, const t_light *const l)
{
	double		proj;
	t_color		color;

	proj = compute_projection(h, l);
	color.r = h->color.r * proj * l->brightness;
	color.g = h->color.g * proj * l->brightness;
	color.b = h->color.b * proj * l->brightness;
	return (color);
}
