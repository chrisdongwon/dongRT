/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:32:04 by cwon              #+#    #+#             */
/*   Updated: 2025/10/12 22:06:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "color.h"

typedef struct s_image	t_image;

struct s_image
{
	char	*data;
	int		bpp;
	int		endian;
	int		height;
	int		size_line;
	int		width;
	void	*ptr;
};

void	img_put_pixel(t_image *img, int x, int y, int color);
void	render(t_scene *scene, t_image *img);

#endif
