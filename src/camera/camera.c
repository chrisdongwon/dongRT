/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:48:11 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 10:59:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>

void	init_camera(t_camera *cam, double aspect_ratio)
{
	double		h;
	double		theta;
	t_vector	horizontal_half;
	t_vector	vertical_half;

	theta = cam->fov * M_PI / 180.0;
	h = tan(theta / 2.0);
	cam->viewport_height = 2.0 * h;
	cam->viewport_width = aspect_ratio * cam->viewport_height;
	update_camera_basis(cam);
	cam->horizontal = scalar_multiplication(cam->viewport_width, cam->basis.u);
	cam->vertical = scalar_multiplication(cam->viewport_height, cam->basis.v);
	horizontal_half = scalar_multiplication(0.5, cam->horizontal);
	vertical_half = scalar_multiplication(0.5, cam->vertical);
	cam->lower_left_corner = vector_subtraction(vector_subtraction(\
vector_subtraction(cam->pos, horizontal_half), vertical_half), cam->basis.w);
}

void	update_camera_basis(t_camera *cam)
{
	cam->basis.w = normalize(scalar_multiplication(-1.0, cam->dir));
	cam->basis.u = normalize(cross_product(cam->up, cam->basis.w));
	cam->basis.v = cross_product(cam->basis.w, cam->basis.u);
}
