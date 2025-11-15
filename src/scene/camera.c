/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:24:57 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 11:42:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>

#include "matrix.h"
#include "mini_rt.h"

static t_matrix	init_matrix(t_camera *const cam)
{
	t_matrix	rot;
	t_matrix	trans;

	rot = basis_matrix(&cam->basis, true);
	trans = translate_matrix(&cam->pos);
	return (matrix_prod(&rot, &trans));
}

void	init_camera(t_camera *const cam)
{
	cam->aspect = (double)WIDTH / (double)HEIGHT;
	cam->scale = tan((cam->fov * 0.5) * M_PI / 180.0);
	cam->basis = init_basis(cam->dir);
	cam->mat = init_matrix(cam);
}
