/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:54:39 by cwon              #+#    #+#             */
/*   Updated: 2026/03/07 15:45:18 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"

#include <math.h>

#include "hit_bonus.h"
#include "object_bonus.h"
#include "sphere_bonus.h"

static void	sphere_uv(const t_vector p, double *u, double *v)
{
	*u = 0.5 + atan2(p.z, p.x) / (2 * M_PI);
	*v = 0.5 - asin(p.y) / M_PI;
}

static double	random_offset(double u, double v, double strength)
{
	return ((sin(u * 120.0 + v * 77.0) * 0.5 + 0.5) * strength);
}

static void	tangent_frame(const t_vector n, t_vector *tan, t_vector *bitan)
{
	t_vector	up;

	up = (t_vector){0, 1, 0};
	if (fabs(dot(n, up)) > 0.99)
		up = (t_vector){1, 0, 0};
	*tan = normalize(cross(up, n));
	*bitan = cross(n, *tan);
}

static void	perturb_normal(t_vector *n, double cu, double cv, double dimple)
{
	t_vector	bitangent;
	t_vector	perturb;
	t_vector	tangent;
	t_vector	temp_u;
	t_vector	temp_v;

	tangent_frame(*n, &tangent, &bitangent);
	temp_u = scale(cu * dimple * 6.0, tangent);
	temp_v = scale(cv * dimple * 6.0, bitangent);
	perturb = add(temp_u, temp_v);
	*n = normalize(add(*n, perturb));
}

void	bump_map(t_hit *hit)
{
	double		cu_cv[2];
	double		dimple;
	double		uv[2];
	t_sphere	*sp;
	t_vector	p;

	sp = (t_sphere *)hit->obj->ptr;
	p = normalize(subtract(hit->point, sp->center));
	sphere_uv(p, &uv[0], &uv[1]);
	cu_cv[0] = fmod(uv[0] * 40.0, 1.0) - 0.5;
	cu_cv[1] = fmod(uv[1] * 40.0, 1.0) - 0.5;
	dimple = fmax(0.0, 0.25 - sqrt(cu_cv[0] * cu_cv[0] + cu_cv[1] * cu_cv[1]) \
+ random_offset(uv[0], uv[1], 0.05));
	perturb_normal(&hit->normal, cu_cv[0], cu_cv[1], dimple);
}
