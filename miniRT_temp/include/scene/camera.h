/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:27:02 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 07:14:29 by cwon             ###   ########.fr       */
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

t_camera	*new_camera(t_vector pos, t_vector dir, double fov);
t_ray		camera_ray(t_camera *cam, double x, double y);

#endif
