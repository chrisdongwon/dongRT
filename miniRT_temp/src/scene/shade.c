/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:10:50 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 13:00:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shade.h"

#include <math.h>

t_color	shade_combine(const t_shade *s, t_color ambient_color)
{
	t_color	diffuse;
	t_color	result;
	t_color	specular;

	diffuse = shade_diffuse(s);
	specular = shade_specular(s);
	result = color_add(ambient_color, color_add(diffuse, specular));
	return (color_clamp(result, 0.0, 1.0));
}

t_color	shade_diffuse(const t_shade *s)
{
	double	intensity;
	t_color	result;

	if (s->light_proj <= 0.0 || s->shadow <= 0.0)
		return (color(0, 0, 0));
	intensity = s->mat.diffuse * s->light_proj * s->shadow;
	result = hadamard_prod(s->mat.color, s->light_color);
	result = color_scale(result, intensity);
	return (color_clamp(result, 0.0, 1.0));
}

t_color	shade_specular(const t_shade *s)
{
	double		angle;
	double		intensity;
	t_color		specular;
	t_vector	reflect_dir;

	if (s->light_proj <= 0.0 || s->shadow <= 0.0)
		return (color(0, 0, 0));
	reflect_dir = vector_reflect(vector_scale(-1.0, s->light_dir), s->normal);
	angle = fmax(0.0, dot_prod(s->view_dir, reflect_dir));
	intensity = pow(angle, s->mat.shininess) * s->mat.specular * s->shadow;
	specular = color_scale(s->light_color, intensity);
	return (color_clamp(specular, 0.0, 1.0));
}

t_shade	shade(t_surface surface, t_light_info light, t_vector view_dir)
{
	t_shade	s;

	s.mat = surface.mat;
	s.normal = surface.normal;
	s.view_dir = normalize(view_dir);
	s.light_dir = light.dir;
	s.light_color = light.color;
	s.shadow = light.shadow;
	s.light_proj = fmax(0.0, dot_prod(s.normal, s.light_dir));
	return (s);
}
