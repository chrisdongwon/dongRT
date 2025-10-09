/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:29:18 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 13:16:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>

#include "ray.h"

t_ray	get_ray(const t_camera *cam, double u_s, double v_s)
{
	t_ray		ray;
	t_vector	v;

	v = vector_addition(vector_addition(cam->lower_left_corner, \
scalar_multiplication(u_s, cam->horizontal)), \
scalar_multiplication(v_s, cam->vertical));
	ray.origin = cam->pos;
	ray.dir = normalize(vector_subtraction(v, cam->pos));
	return (ray);
}
