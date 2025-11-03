/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:08:23 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 20:26:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURFACE_H
# define SURFACE_H

# include "material.h"
# include "vector.h"

typedef struct s_surface	t_surface;

struct s_surface
{
	t_material	mat;
	t_vector	normal;
	t_vector	hit_point;
};

// surface.c
t_surface	surface(t_material m, t_vector normal, t_vector hit_point);

#endif
