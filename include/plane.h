/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:36:53 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 08:49:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "rgb.h"
# include "vector.h"

typedef struct s_plane	t_plane;

struct s_plane
{
	t_rgb		color;
	t_vector	normal;
	t_vector	pos;
};

void	print_plane(void *ptr);

#endif
