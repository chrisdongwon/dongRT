/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:24:03 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 14:33:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

#include "frame.h"

t_ray	generate_ray(t_frame *frame, int x, int y)
{
	double		right;
	double		up;
	t_ray		ray;

	right = (x + 0.5) * frame->pixel_w - frame->viewport_w / 2.0;
	up = frame->viewport_h / 2.0 - (y + 0.5) * frame->pixel_h;
	ray.dir = add(scale(right, frame->basis.right), scale(up, frame->basis.up));
	ray.dir = add(ray.dir, scale(-frame->focal_len, frame->basis.forward));
	ray.dir = normalize(ray.dir);
	ray.origin = frame->pos;
	return (ray);
}
