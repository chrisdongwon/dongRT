/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:01:33 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 15:58:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_camera	t_camera;
typedef struct s_ray	t_ray;

struct s_ray
{
	t_vector	origin;
	t_vector	dir;
};

// ray.c
t_ray	generate_ray(const t_camera *cam, int px, int py);

#endif
