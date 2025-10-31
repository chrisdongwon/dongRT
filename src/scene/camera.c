/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:37:42 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 07:14:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>
#include <stdlib.h>

#include "mini_rt.h"

t_camera	*new_camera(t_vector pos, t_vector dir, double fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (cam != NULL)
	{
		cam->aspect = (double)WIN_WIDTH / (double)WIN_HEIGHT;
		cam->basis = basis(dir, vector(0.0, 1.0, 0.0));
		cam->fov = fov;
		cam->pos = pos;
		cam->scale = tan((fov * 0.5) * M_PI / 180);
	}
	return (cam);
}

t_ray	camera_ray(t_camera *cam, double x, double y)
{
	double		j_scale;
	t_vector	dir;
	t_vector	j_offset;
	t_vector	k_offset;

	j_scale = cam->aspect * cam->scale;
	j_offset = vector_scale((2 * x - 1) * j_scale, cam->basis.j);
	k_offset = vector_scale((1 - 2 * y) * cam->scale, cam->basis.k);
	dir = vector_add(vector_add(j_offset, k_offset), cam->basis.i);
	return (ray(cam->pos, dir));
}
