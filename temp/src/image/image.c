/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:45:21 by cwon              #+#    #+#             */
/*   Updated: 2025/10/12 22:02:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

#include <stdlib.h>

#include "ray.h"
#include "scene.h"
#include "color.h"

#define SAMPLES_PER_PIXEL  50

void	img_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}


static double	random_double(void)
{
	return ((double)rand() / (double)RAND_MAX);
}

static t_color	average_color(t_color accum, int samples)
{
	t_color	out;

	out.x = accum.x / samples;
	out.y = accum.y / samples;
	out.z = accum.z / samples;
	return (out);
}

void	render(t_scene *scene, t_image *img)
{
	int			x;
	int			y;
	int			s;
	double		u;
	double		v;
	t_color		accum;
	t_color		sample;
	t_ray		ray;
	t_rgb		final;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			accum = (t_color){0, 0, 0};
			s = 0;
			while (s < SAMPLES_PER_PIXEL)
			{
				u = ((double)x + random_double()) / (img->width - 1);
				v = ((double)(img->height - 1 - y) + random_double()) / (img->height - 1);
				ray = get_ray(&scene->camera, u, v);
				sample = ray_color(&ray, scene);
				accum = color_add(accum, sample);
				s++;
			}
			accum = average_color(accum, SAMPLES_PER_PIXEL);
			final = color_to_rgb(accum);
			img_put_pixel(img, x, y, rgb_to_int(final));
			x++;
		}
		y++;
	}
}
