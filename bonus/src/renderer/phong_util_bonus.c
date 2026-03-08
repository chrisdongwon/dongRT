/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:48:12 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 13:50:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"

#include "camera_bonus.h"
#include "light_bonus.h"
#include "spotlight_bonus.h"
#include "scene_bonus.h"

t_color	contribute_light(const t_hit *h, const t_scene *s, t_color color)
{
	t_color	diff;
	t_color	spec;

	diff = phong_diffuse(h, s->light, color);
	spec = phong_specular(h, s->light, s->camera);
	return (scale_color(add_color(diff, spec), s->light->brightness));
}

t_color	contribute_spot(const t_hit *h, const t_spotlight *s, \
const t_camera *c, t_color obj_color)
{
	t_color	diff;
	t_color	spec;
	t_light	tmp;

	tmp.pos = s->pos;
	tmp.color = s->color;
	tmp.brightness = s->brightness;
	diff = phong_diffuse(h, &tmp, obj_color);
	spec = phong_specular(h, &tmp, c);
	return (scale_color(add_color(diff, spec), s->brightness));
}
