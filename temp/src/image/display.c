/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:05:03 by cwon              #+#    #+#             */
/*   Updated: 2025/10/12 22:06:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#include <stdlib.h>
#include <stdio.h>

#include "image.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void	display_scene(t_scene *scene)
{
	t_mlx	mlx;
	t_color	color;
	int		x;
	int		y;

	mlx.width = WINDOW_WIDTH;
	mlx.height = WINDOW_HEIGHT;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (perror("mlx_init"), (void)0);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "miniRT");
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);

	for (y = 0; y < mlx.height; ++y)
	{
		for (x = 0; x < mlx.width; ++x)
		{
			color = ray_color_for_pixel(scene, x, y, mlx.width, mlx.height);
			put_pixel(&mlx, x, y, rgb_to_int(color));
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 17, 0, (int (*)())close_window, &mlx);
	mlx_loop(mlx.mlx);
}
