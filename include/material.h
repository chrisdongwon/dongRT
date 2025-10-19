/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:32:53 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 15:40:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct s_material	t_material;

struct s_material
{
	double	diffuse;	// Diffuse reflection coefficient (0–1)
	double	ior;		// Index of refraction (1.0 = air, 1.5 = glass)
	double	reflection;	// Reflection ratio (0–1)
	double	refraction;	// Refraction ratio (0–1, optional)
	double	shininess;	// Specular exponent (higher = smaller highlight)
	double	specular;	// Specular reflection coefficient (0–1)
	t_color	color;		// Base (albedo) color of the surface
};

// material.c
t_material	default_material(void);

#endif
