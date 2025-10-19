/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:57:34 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 13:17:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include <stdbool.h>

# include "interval.h"
# include "rgb.h"
# include "vector.h"

typedef struct s_hit	t_hit;
typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;
typedef struct s_sphere	t_cylinder;
typedef struct s_sphere	t_plane;
typedef struct s_sphere	t_sphere;

struct					s_cylinder;
struct					s_plane;
struct					s_ray;
struct					s_scene;
struct					s_sphere;

struct s_hit
{
	bool		is_front;
	double		t;
	t_rgb		color;
	t_vector	normal;
	t_vector	point;
};

// hit_cylinder.c
bool	hit_cylinder(const t_cylinder *cyl, const t_ray *ray, \
t_interval range, t_hit *record);

// hit_plane.c
bool	hit_plane(const t_plane *plane, const t_ray *ray, t_interval range, \
t_hit *record);

// hit_sphere.c
bool	hit_sphere(const t_sphere *sphere, const t_ray *ray, t_interval range, \
t_hit *record);

// hit_util.c
void	reorient_normal(t_ray *ray, t_vector outward_normal, t_hit *record);

// hit.c
bool	hit_scene(const t_scene *scene, const t_ray *ray, t_interval range, \
t_hit *record);

#endif
