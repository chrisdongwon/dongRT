/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:42:58 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 07:32:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_add(t_color a, t_color b)
{
	return (color(a.r + b.r, a.g + b.g, a.b + b.b));
}

t_color	color_clamp(t_color c, double min, double max)
{
	if (c.r < min)
		c.r = min;
	else if (c.r > max)
		c.r = max;
	if (c.g < min)
		c.g = min;
	else if (c.g > max)
		c.g = max;
	if (c.b < min)
		c.b = min;
	else if (c.b > max)
		c.b = max;
	return (c);
}

t_color	color_scale(t_color c, double s)
{
	return (color(c.r * s, c.g * s, c.b * s));
}

t_color	color(double r, double g, double b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color	hadamard_prod(t_color a, t_color b)
{
	return (color(a.r * b.r, a.g * b.g, a.b * b.b));
}
