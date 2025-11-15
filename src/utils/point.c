/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:43:26 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 11:36:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

#include "camera.h"
#include "mini_rt.h"

t_point	init_ndc(double px, double py)
{
	t_point	ndc;

	ndc.x = (px + 0.5) / (double)WIDTH;
	ndc.y = (py + 0.5) / (double)HEIGHT;
	return (ndc);
}

t_vector	ssc_to_vector(const t_camera *cam, const t_point *p)
{
	t_vector	v;

	v.x = p->x * cam->scale * cam->aspect;
	v.y = p->y * cam->scale;
	v.z = -1.0;
	return (normalize(v));
}

void	ndc_to_ssc(t_point *const p)
{
	p->x = 2.0 * p->x - 1.0;
	p->y = 1.0 - 2.0 * p->y;
}
