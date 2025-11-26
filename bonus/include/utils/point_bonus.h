/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:31:30 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:41:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_BONUS_H
# define POINT_BONUS_H

# include "vector_bonus.h"

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
