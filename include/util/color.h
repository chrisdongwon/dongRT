/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:22:19 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 07:32:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color	t_color;

struct s_color // scaled from [0,255] to [0, 1]
{
	double	r;
	double	g;
	double	b;
};

// color_transform.c
int		color_to_int(t_color c);
t_color	color_average(const t_color *colors, int n);

// color.c
t_color	color_add(t_color a, t_color b);
t_color	color_clamp(t_color c, double min, double max);
t_color	color_scale(t_color c, double s);
t_color	color(double r, double g, double b);
t_color	hadamard_prod(t_color a, t_color b);

#endif
