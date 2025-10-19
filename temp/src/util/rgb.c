/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:30:25 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 07:50:36 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"

#include <stdio.h>

#include "libft.h"

bool	is_valid_rgb(t_rgb *color)
{
	return (ft_isbetween(color->r, 0, 255) && ft_isbetween(color->g, 0, 255) \
&& ft_isbetween(color->b, 0, 255));
}

void	init_rgb(t_rgb *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	print_rgb(t_rgb *c)
{
	printf("(%d, %d, %d)", c->r, c->g, c->b);
}
