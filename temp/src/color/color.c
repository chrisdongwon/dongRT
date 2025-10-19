/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:27:59 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 13:49:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

#include <math.h>

t_color	color(double r, double g, double b)
{
	t_color	c;

	c.x = r;
	c.y = g;
	c.z = b;
	return (c);
}

t_color	color_add(t_color a, t_color b)
{
	return (vector_addition(a, b));
}

t_color	color_multiply(t_color a, double scalar)
{
	return (scalar_multiplication(scalar, a));
}

t_color	color_hadamard(t_color a, t_color b)
{
	return ((t_color){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_color	color_clamp(t_color c)
{
	c.x = fmin(fmax(c.x, 0.0), 1.0);
	c.y = fmin(fmax(c.y, 0.0), 1.0);
	c.z = fmin(fmax(c.z, 0.0), 1.0);
	return (c);
}
