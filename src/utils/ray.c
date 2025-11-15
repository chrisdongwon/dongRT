/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 12:18:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

#include "camera.h"
#include "point.h"

t_ray	generate_ray(const t_camera *const cam, double px, double py)
{
	t_point		p;
	t_ray		r;
	t_vector	v;
	t_vector	zero_vector;

	zero_vector = (t_vector){0, 0, 0};
	p = init_ndc(px, py);
	ndc_to_ssc(&p);
	v = ssc_to_vector(cam, &p);
	r.dir = normalize(transform(&cam->mat, &v, false));
	r.origin = transform(&cam->mat, &zero_vector, true);
	return (r);
}
