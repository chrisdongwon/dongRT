/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:27:14 by cwon              #+#    #+#             */
/*   Updated: 2025/12/11 14:41:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_BONUS_H
# define HIT_BONUS_H

# include "color_bonus.h"
# include "vector_bonus.h"

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

// hit_cylinder.c
t_hit	hit_cylinder(const t_ray *r, const t_object *obj);

// hit_paraboloid.c
t_hit	hit_paraboloid(const t_ray *r, const t_object *obj);

// hit_plane.c
t_hit	hit_plane(const t_ray *r, const t_object *obj);

// hit_sphere.c
t_hit	hit_sphere(const t_ray *r, const t_object *obj);

// hit.c
t_hit	hit_scene(const t_scene *s, const t_ray *r);
void	init_hit(t_hit *h);

// shade.c
t_color	lambertian_shade(const t_hit *h, const t_light *l);
t_color	phong_shade(const t_hit *h, const t_light *l);

#endif
