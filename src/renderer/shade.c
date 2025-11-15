/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:28:28 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 13:40:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "light.h"

static double	compute_proj(const t_hit *const h, const t_vector *const dir)
{
	double	proj;

	proj = dot(h->normal, *dir);
	if (proj < 0)
		proj = 0;
	return (proj);
}

static t_color	apply_diffusion(const t_hit *const h, double diffuse)
{
	t_color	color;

	color.r = h->color.r * diffuse;
	color.g = h->color.g * diffuse;
	color.b = h->color.b * diffuse;
	return (color);
}

t_color	lambert_shade(const t_hit *const h, const t_light *const l)
{
	double		proj;
	t_vector	dir;

	dir = normalize(subtract(l->pos, h->point));
	proj = compute_proj(h, &dir);
	return (apply_diffusion(h, l->brightness * proj));
}
