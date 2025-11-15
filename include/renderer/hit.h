/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:27:14 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 13:31:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "color.h"
# include "vector.h"

typedef struct s_hit	t_hit;
typedef struct s_light	t_light;
typedef struct s_ray	t_ray;
typedef struct s_sphere	t_sphere;

struct s_hit
{
	bool		is_hit;
	double		t;
	t_color		color;
	t_vector	normal;
	t_vector	point;
};

// hit_sphere.c
t_hit	hit_sphere(const t_ray *const r, const t_sphere *const s);

// hit.c
void	init_hit(t_hit *const h);

// shade.c
t_color	lambert_shade(const t_hit *const h, const t_light *const l);

#endif
