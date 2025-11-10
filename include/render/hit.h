/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:46:37 by cwon              #+#    #+#             */
/*   Updated: 2025/11/10 15:38:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include <stdbool.h>

# include "color.h"
# include "vector.h"

typedef struct s_hit	t_hit;
typedef struct s_object	t_object;
typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;

struct s_hit
{
	bool		hit;
	double		t;
	t_color		color;
	t_object	*obj;
	t_vector	normal;
	t_vector	point;
};

// hit_utils.c ?
// set_face_normal ?

// hit_sphere.c
bool	hit_sphere(t_object *obj, t_ray *r, t_hit *h);

// scene_hit.c
bool	scene_hit(t_scene *scene, t_ray ray, t_hit *closest_hit);

#endif
