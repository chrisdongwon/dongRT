/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:37:11 by cwon             ###   ########.fr       */
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
int	color_to_rgb(const t_color *c);

#endif
