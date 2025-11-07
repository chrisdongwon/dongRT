/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:13:35 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 14:18:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame.h"

#include <math.h>

#include "mini_rt.h"

t_frame	init_frame(t_camera cam)
{
	double	aspect;
	double	fov_rad;
	t_frame	frame;

	aspect = (double)WIDTH / (double)HEIGHT;
	fov_rad = cam.fov * M_PI / 180.0;
	frame.basis = camera_basis(cam.dir);
	frame.focal_len = 1.0;
	frame.pos = cam.pos;
	frame.viewport_h = 2.0 * tan(fov_rad / 2.0) * frame.focal_len;
	frame.viewport_w = frame.viewport_h * aspect;
	frame.pixel_w = frame.viewport_w / (double)WIDTH;
	frame.pixel_h = frame.viewport_h / (double)HEIGHT;
	return (frame);
}
