/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:04 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 13:22:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"

#include "camera_bonus.h"
#include "hit_bonus.h"
#include "mini_rt_bonus.h"
#include "minilibx_bonus.h"
#include "mlx.h"
#include "object_bonus.h"
#include "ray_bonus.h"
#include "scene_bonus.h"

static int	render_pixel(int px, int py, const t_scene *s)
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;
	t_color	surface;

	ray = generate_ray(s->camera, px, py);
	hit = hit_scene(s, &ray);
	if (hit.is_hit)
	{
		if (hit.obj->type == SPHERE)
			bump_map(&hit);
		surface = hit.obj->color;
		if (hit.obj->type == PLANE)
			surface = checkerboard(&hit);
		color = phong_shade(&hit, s, surface);
		return (color_to_rgb(&color));
	}
	return (create_trgb(0, px * 255 / WIDTH, py * 255 / HEIGHT, 128));
}

static void	render_scene_image(t_renderer *r)
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
}

static int	redraw(void *param)
{
	t_minilibx	*m;
	t_renderer	*r;

	r = (t_renderer *)param;
	m = r->minilibx;
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}

static void	render_scene(t_renderer *r)
{
	t_minilibx	*m;

	m = r->minilibx;
	render_scene_image(r);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_key_hook(m->win, handle_key, r);
	mlx_hook(m->win, X_BUTTON, 0, close_window, r);
	mlx_expose_hook(m->win, redraw, r);
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
