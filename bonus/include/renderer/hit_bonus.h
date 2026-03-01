/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:27:14 by cwon              #+#    #+#             */
/*   Updated: 2026/03/01 14:51:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_BONUS_H
# define HIT_BONUS_H

# include "vector_bonus.h"

typedef struct s_camera	t_camera;
typedef struct s_hit	t_hit;
typedef struct s_light	t_light;
typedef struct s_list	t_list;
typedef struct s_object	t_object;
typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;

struct s_hit
{
	bool			is_hit;
	const t_object	*obj;
	double			t;
	t_vector		normal;
	t_vector		point;
};

// hit_cylinder_bonus.c
t_hit	hit_cylinder(const t_ray *r, const t_object *obj);

// hit_paraboloid_bonus.c
t_hit	hit_paraboloid(const t_ray *r, const t_object *obj);

// hit_plane_bonus.c
t_hit	hit_plane(const t_ray *r, const t_object *obj);

// hit_sphere_bonus.c
t_hit	hit_sphere(const t_ray *r, const t_object *obj);

// hit_bonus.c
bool	in_shadow(const t_hit *h, t_vector light_pos, t_list *objects);
bool	intersect(const t_object *obj, const t_ray *ray, double *t);
t_hit	hit_scene(const t_scene *s, const t_ray *r);
void	init_hit(t_hit *h);

#endif
