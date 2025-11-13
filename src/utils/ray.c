/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/13 15:43:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

#include "camera.h"
#include "mini_rt.h"

// static t_vector	compute_dir(t_basis b, const double ndc_x, const double ndc_y)
// {
// 	t_vector	dir;

// 	dir = scale(ndc_x, b.right);
// 	dir = add(dir, scale(ndc_y, b.up));
// 	dir = add(dir, b.forward);
// 	return (normalize(dir));
// }

t_ray	generate_ray(const t_camera *c, int x, int y)
{
	// const double	ndc_x = (2 * (x + 0.5) / WIDTH - 1) * c->aspect * c->scale;
	// const double	ndc_y = (1 - 2 * (y + 0.5) / HEIGHT) * c->scale;
	// t_ray			ray;

	// ray.origin = c->pos;
	// ray.dir = compute_dir(c->basis, ndc_x, ndc_y);
	// return (ray);
}
