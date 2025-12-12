/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:27:14 by cwon              #+#    #+#             */
/*   Updated: 2025/12/12 14:09:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_BONUS_H
# define HIT_BONUS_H

# define KA 0.1
# define KD 0.9
# define KS 0.3
# define SHININESS 30

# include "color_bonus.h"
# include "vector_bonus.h"

typedef struct s_camera	t_camera;
typedef struct s_hit	t_hit;
typedef struct s_light	t_light;
typedef struct s_object	t_object;
typedef struct s_ray	t_ray;
typedef struct s_scene	t_scene;

struct s_hit
{
	bool		is_hit;
	double		t;
	t_color		color;
	t_vector	normal;
	t_vector	point;
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
t_hit	hit_scene(const t_scene *s, const t_ray *r);
void	init_hit(t_hit *h);

// lambertian_bonus.c
t_color	lambertian_shade(const t_hit *h, const t_light *l);

// phong_bonus.c
t_color	phong_shade(const t_hit *h, const t_light *l, const t_camera *c);

#endif
