/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:13 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 17:41:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

#include "camera_bonus.h"
#include "mini_rt_bonus.h"
#include "point_bonus.h"

t_ray	generate_ray(const t_camera *cam, double px, double py)
{
	t_point		p;
	t_ray		ray;
	t_vector	v;

	p.x = (px + 0.5) / WIDTH;
	p.y = (py + 0.5) / HEIGHT;
	p.x = 2.0 * p.x - 1.0;
	p.y = 1.0 - 2.0 * p.y;
	v = add(cam->basis.forward, add(scale(p.x * cam->scale * cam->aspect, \
cam->basis.right), scale(p.y * cam->scale, cam->basis.up)));
	ray.dir = normalize(v);
	ray.origin = cam->pos;
	return (ray);
}
