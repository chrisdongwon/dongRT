/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/10 11:05:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color	t_color;

// scaled from [0, 255] to [0, 1]
struct s_color
{
	double	r;
	double	g;
	double	b;
};

#endif
