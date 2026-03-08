/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:31:30 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 15:45:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "vector.h"

typedef struct s_point	t_point;
typedef struct s_camera	t_camera;

struct s_point
{
	double	x;
	double	y;
};

// point.c
t_point		init_ndc(double px, double py);
void		ndc_to_ssc(t_point *p);

#endif
