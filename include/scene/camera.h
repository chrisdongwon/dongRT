/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:27:02 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 15:32:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "basis.h"
# include "ray.h"

typedef struct s_camera	t_camera;

struct s_camera
{
	double		aspect;
	double		fov;
	double		scale;
	t_basis		basis;
	t_vector	pos;
};

// camera.c

// change this to new_camera (allocated)
// is aspect necessary?
t_camera	camera(t_vector origin, t_vector dir, double fov, double aspect);
t_ray		camera_ray(t_camera *cam, double x, double y);

#endif
