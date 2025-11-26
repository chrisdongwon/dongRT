/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:24:57 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:45:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_bonus.h"

#include <math.h>

#include "matrix_bonus.h"
#include "mini_rt_bonus.h"

static t_matrix	init_matrix(t_camera *cam)
{
	t_matrix	rot;
	t_matrix	trans;

	rot = basis_matrix(&cam->basis, true);
	trans = translate_matrix(&cam->pos);
	return (matrix_prod(&trans, &rot));
}

void	init_camera(t_camera *cam)
{
	cam->aspect = (double)WIDTH / (double)HEIGHT;
	cam->scale = tan((cam->fov * 0.5) * M_PI / 180.0);
	cam->basis = init_basis(cam->dir);
	cam->mat = init_matrix(cam);
}
