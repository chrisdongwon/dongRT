/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:20:09 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 14:48:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "rgb.h"
# include "vector.h"

typedef t_vector	t_color;

// color_convert.c
int		color_to_int(t_color c);
t_color	rgb_to_color(t_rgb rgb);
t_rgb	color_to_rgb(t_color c);

// color.c
t_color	color_add(t_color a, t_color b);
t_color	color_clamp(t_color c);
t_color	color_hadamard(t_color a, t_color b);
t_color	color_multiply(t_color a, double scalar);
t_color	color(double r, double g, double b);

// ray_color.c
t_color	ray_color(const t_ray *ray, const t_scene *scene);

#endif
