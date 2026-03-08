/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:42:18 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 16:11:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

#include <math.h>

int	color_to_rgb(const t_color *c)
{
	int	r;
	int	g;
	int	b;

	r = fmin(fmax(c->r * 255.0, 0.0), 255.0);
	g = fmin(fmax(c->g * 255.0, 0.0), 255.0);
	b = fmin(fmax(c->b * 255.0, 0.0), 255.0);
	return (r << 16 | g << 8 | b);
}

t_color	add_color(t_color a, t_color b)
{
	t_color	result;

	result.r = fmin(a.r + b.r, 255.0);
	result.g = fmin(a.g + b.g, 255.0);
	result.b = fmin(a.b + b.b, 255.0);
	return (result);
}

t_color	scale_color(t_color c, double factor)
{
	t_color	result;

	result.r = fmin(fmax(c.r * factor, 0.0), 255.0);
	result.g = fmin(fmax(c.g * factor, 0.0), 255.0);
	result.b = fmin(fmax(c.b * factor, 0.0), 255.0);
	return (result);
}
