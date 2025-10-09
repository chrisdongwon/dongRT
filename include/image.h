/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:32:04 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 14:45:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "color.h"
//# include "mlx.h"

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

#endif
