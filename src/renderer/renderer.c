/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:19:07 by cwon              #+#    #+#             */
/*   Updated: 2025/11/13 14:29:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include <stdlib.h>

#include "camera.h"
#include "mini_rt.h"
#include "minilibx.h"
#include "mlx.h"
#include "scene.h"

void	init_renderer(t_renderer *r, t_scene *s, t_minilibx *m)
{
	if (!init_minilibx(m))
		mini_rt_error(s);
	init_camera(s->camera);
	r->scene = s;
	r->minilibx = m;
}

void	flush_renderer(t_renderer *r)
{
	if (r->minilibx->img != NULL)
		mlx_destroy_image(r->minilibx->mlx, r->minilibx->img);
	if (r->minilibx->win != NULL)
		mlx_destroy_window(r->minilibx->mlx, r->minilibx->win);
	if (r->minilibx->mlx != NULL)
	{
		mlx_destroy_display(r->minilibx->mlx);
		free(r->minilibx->mlx);
	}
}
