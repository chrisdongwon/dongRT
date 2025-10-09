/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:45:21 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 14:50:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

#include "ray.h"
#include "scene.h"
#include "color.h"

void	img_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// to do: render function