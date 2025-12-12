/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:42:18 by cwon              #+#    #+#             */
/*   Updated: 2025/12/12 14:11:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_bonus.h"

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
	t_color	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	return (c);
}

t_color	multiply_color(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r * b.r;
	c.g = a.g * b.g;
	c.b = a.b * b.b;
	return (c);
}

t_color	scale_color(t_color c, double scale)
{
	c.r *= scale;
	c.g *= scale;
	c.b *= scale;
	return (c);
}
