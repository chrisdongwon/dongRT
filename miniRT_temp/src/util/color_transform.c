/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:45:55 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 14:46:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_to_int(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(c.r * 255.0);
	g = (int)(c.g * 255.0);
	b = (int)(c.b * 255.0);
	return ((r << 16) | (g << 8) | b);
}

t_color	color_average(const t_color *colors, int n)
{
	int		i;
	t_color	sum;

	sum = color(0, 0, 0);
	i = 0;
	while (i < n)
	{
		sum.r += colors[i].r;
		sum.g += colors[i].g;
		sum.b += colors[i].b;
		i++;
	}
	sum.r /= n;
	sum.g /= n;
	sum.b /= n;
	return (sum);
}
