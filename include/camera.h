/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:01:28 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 14:49:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "basis.h"
# include "vector.h"

typedef struct s_camera	t_camera;

struct s_camera
{
	double		fov;
	double		viewport_height;
	double		viewport_width;
	t_basis		basis;
	t_vector	dir;
	t_vector	horizontal;
	t_vector	lower_left_corner;
	t_vector	pos;
	t_vector	up;
	t_vector	vertical;
};

// camera.c
void	init_camera(t_camera *cam, double aspect_ratio);
void	update_camera_basis(t_camera *cam);

// get_ray.c
t_ray	get_ray(const t_camera *cam, double u_s, double v_s);

#endif
