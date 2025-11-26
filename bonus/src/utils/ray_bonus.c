/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:45:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

#include "camera_bonus.h"
#include "point_bonus.h"

t_ray	generate_ray(const t_camera *cam, double px, double py)
{
	static const t_vector	origin = {0, 0, 0};
	t_point					p;
	t_ray					r;
	t_vector				v;

	p = init_ndc(px, py);
	ndc_to_ssc(&p);
	v = ssc_to_vector(cam, &p);
	r.dir = normalize(transform(&cam->mat, &v, false));
	r.origin = transform(&cam->mat, &origin, true);
	return (r);
}
