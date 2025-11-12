/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:14:03 by cwon              #+#    #+#             */
/*   Updated: 2025/11/12 15:50:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

#include <stdlib.h>

#include "mini_rt.h"
#include "mlx.h"
#include "renderer.h"
#include "scene.h"

bool	init_minilibx(t_minilibx *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (false);
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "miniRT");
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->ll, &m->endian);
	return (true);
}

int	close_window(t_renderer *r)
{
	flush_renderer(r);
	flush_scene(r->scene);
	exit(EXIT_SUCCESS);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	handle_key(int keycode, t_renderer *r)
{
	if (keycode == ESC_KEY)
		close_window(r);
	return (0);
}

void	put_pixel(t_minilibx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->ll + x * (m->bpp / 8));
	*(unsigned int *)dst = color;
}
