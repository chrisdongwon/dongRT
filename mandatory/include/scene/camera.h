/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:16 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 17:35:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "basis.h"

typedef struct s_camera	t_camera;

struct s_camera
{
	double		aspect;
	double		fov;
	double		scale;
	t_vector	dir;
	t_vector	pos;
	t_basis		basis;
};

// camera.c
void	init_camera(t_camera *cam);

#endif
