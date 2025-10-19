/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:27:26 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 20:28:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_INFO_H
# define LIGHT_INFO_H

# include "color.h"
# include "vector.h"

typedef struct s_light_info	t_light_info;

struct s_light_info
{
	double		shadow;	// shadow factor [0–1]
	t_color		color;	// light color/intensity
	t_vector	dir;	// direction from point to light
};

t_light_info	light_info(t_vector dir, t_color color, double shadow);

#endif
