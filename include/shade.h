/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:07:31 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 08:26:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_H
# define SHADE_H

# include "material.h"
# include "vector.h"
# include "light_info.h"
# include "surface.h"

typedef struct s_shade	t_shade;

struct s_shade
{
	double		light_proj;
	double		shadow;
	t_color		light_color;
	t_material	mat;
	t_vector	light_dir;
	t_vector	normal;
	t_vector	view_dir;
};

// shade.c
t_color	shade_combine(const t_shade *s, t_color ambient_color);
t_color	shade_diffuse(const t_shade *s);
t_color	shade_specular(const t_shade *s);
t_shade	shade(t_surface surface, t_light_info light, t_vector view_dir);

#endif
