/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:52:00 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 10:30:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_ray	t_ray;

struct s_ray
{
	t_vector	dir;
	t_vector	origin;
};

// ray.c
t_vector	ray_at(t_ray *r, double t);

#endif
