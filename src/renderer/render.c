/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:04 by cwon              #+#    #+#             */
/*   Updated: 2025/11/18 15:28:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include <stdio.h>

#include "hit.h"
#include "mini_rt.h"
#include "minilibx.h"
#include "mlx.h"
#include "ray.h"
#include "scene.h"

static int	render_pixel(int px, int py, const t_scene *const s)
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;

	ray = generate_ray(s->camera, px, py);
	hit = hit_scene(s, &ray);
	if (hit.is_hit)
	{
		color = lambertian_shade(&hit, s->light);
		return (color_to_rgb(&color));
	}
	//return (create_trgb(0, 255, 255, 255));
	return (create_trgb(0, px * 255 / WIDTH, py * 255 / HEIGHT, 128));
}

static void	render_scene(t_renderer *const r)
{
	int			trgb;
	int			x;
	int			y;
	t_minilibx	*m;

	m = r->minilibx;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			trgb = render_pixel(x, y, r->scene);
			put_pixel(m, x, y, trgb);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_key_hook(m->win, handle_key, r);
	mlx_hook(m->win, X_BUTTON, 0, close_window, r);
	mlx_loop(m->mlx);
}

void	render(t_scene *const s)
{
	t_renderer	renderer;
	t_minilibx	minilibx;

	renderer = init_renderer(s, &minilibx);
	render_scene(&renderer);
	flush_renderer(&renderer);
}
