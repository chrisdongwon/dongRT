/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 15:58:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

#include "camera.h"
#include "point.h"

t_ray	generate_ray(const t_camera *cam, double px, double py)
{
	t_point		p;
	t_vector	v;

	p = init_ndc(px, py);
	ndc_to_ssc(&p);
	v = ssc_to_vector(cam, )
}
