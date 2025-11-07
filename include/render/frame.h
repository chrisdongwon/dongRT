/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:10:54 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 14:14:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include "basis.h"
# include "camera.h"

typedef struct s_frame	t_frame;

struct s_frame
{
	double		focal_len;
	double		pixel_h;
	double		pixel_w;
	double		viewport_h;
	double		viewport_w;
	t_basis		basis;
	t_vector	pos;
};

// frame.c
t_frame	init_frame(t_camera cam);

#endif
