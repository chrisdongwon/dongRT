/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:56 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 16:04:36 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color	t_color;

struct s_color
{
	double	r;
	double	g;
	double	b;
};

// color.c
int		color_to_rgb(const t_color *c);
t_color	add_color(t_color a, t_color b);
t_color	scale_color(t_color a, double factor);

#endif
