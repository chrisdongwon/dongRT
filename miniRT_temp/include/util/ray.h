/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:20:40 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 23:34:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

# ifndef RAY_EPS
#  define RAY_EPS 1e-6
# endif

typedef struct s_ray	t_ray;

struct s_ray
{
	t_vector	origin;
	t_vector	dir;
};

// ray.c
t_ray		ray_reflect(const t_ray *ray, t_vector normal, t_vector hit_point);
t_ray		ray(t_vector origin, t_vector direction);
t_vector	ray_at(const t_ray *ray, double t);
t_vector	ray_project_point(const t_ray *ray, t_vector point);

#endif
