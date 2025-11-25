/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:31:30 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 14:50:19 by cwon             ###   ########.fr       */
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
t_vector	ssc_to_vector(const t_camera *cam, const t_point *p);
void		ndc_to_ssc(t_point *p);

#endif
