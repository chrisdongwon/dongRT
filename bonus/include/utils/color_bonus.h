/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:56 by cwon              #+#    #+#             */
/*   Updated: 2025/12/12 13:50:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_BONUS_H
# define COLOR_BONUS_H

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
t_color	multiply_color(t_color a, t_color b);
t_color	scale_color(t_color c, double scale);

#endif
