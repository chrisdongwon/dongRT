/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:41:17 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 13:41:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_to_int(t_color c)
{
	t_rgb	rgb;

	rgb = color_to_rgb(c);
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

t_color	rgb_to_color(t_rgb rgb)
{
	return ((t_color){rgb.r / 255.0, rgb.g / 255.0, rgb.b / 255.0});
}

t_rgb	color_to_rgb(t_color c)
{
	t_rgb	rgb;

	c = color_clamp(c);
	rgb.r = (int)(255.999 * c.x);
	rgb.g = (int)(255.999 * c.y);
	rgb.b = (int)(255.999 * c.z);
	return (rgb);
}
