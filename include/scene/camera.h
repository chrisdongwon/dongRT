/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:16 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 15:50:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "basis.h"
# include "matrix.h"

typedef struct s_camera	t_camera;

struct s_camera
{
	double		aspect;
	double		fov;
	double		scale;
	t_vector	dir;
	t_vector	pos;
	t_basis		basis;
	t_matrix	mat;
};

// camera.c
void	init_camera(t_camera *cam);

#endif
