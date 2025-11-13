/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:24:57 by cwon              #+#    #+#             */
/*   Updated: 2025/11/13 15:57:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <math.h>

#include "mini_rt.h"

void	init_camera(t_camera *cam)
{
	cam->aspect = (double)WIDTH / (double)HEIGHT;
	cam->basis = init_basis(cam->dir);
	cam->scale = tan((cam->fov * 0.5) * M_PI / 180.0);
	
}
