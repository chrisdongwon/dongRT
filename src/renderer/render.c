/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:04 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 14:33:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include "mini_rt.h"
#include "minilibx.h"
#include "mlx.h"
#include "scene.h"
#include "color.h"
#include "ray.h"
#include "hit.h"
#include "camera.h"
#include "light.h"
#include "object.h"
#include "libft.h"

// need:
// hit dispatcher
// see if intersection works
// then color shit in
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
			trgb = create_trgb(0, x * 255 / WIDTH, y * 255 / HEIGHT, 128);
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
