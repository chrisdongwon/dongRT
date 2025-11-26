/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:16 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:41:40 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

# include "basis_bonus.h"
# include "matrix_bonus.h"

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
