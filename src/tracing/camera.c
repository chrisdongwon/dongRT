/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:29:18 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 15:40:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "ray.h"

// can this function be broken down further?
t_ray	get_ray(const t_camera *cam, double u_s, double v_s, double aspect_ratio)
{
	t_ray	ray;
	double	theta = cam->fov * M_PI / 180.0;
	double	plane_height = 2.0 * tan(theta / 2.0);
	double	plane_width = aspect_ratio * plane_height;

	t_vector lower_left = vector_subtraction(
		vector_subtraction(
			vector_subtraction(cam->pos,
								scalar_multiplication(0.5 * plane_width, cam->basis.u)),
			scalar_multiplication(0.5 * plane_height, cam->basis.v)),
		cam->basis.w
	);

	t_vector offset_h = scalar_multiplication(u_s * plane_width, cam->basis.u);
	t_vector offset_v = scalar_multiplication(v_s * plane_height, cam->basis.v);

	ray.origin = cam->pos;
	ray.dir = normalize(vector_subtraction(
		vector_addition(vector_addition(lower_left, offset_h), offset_v),
		cam->pos
	));
	return ray;
}
