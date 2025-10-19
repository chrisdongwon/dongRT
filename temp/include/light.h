/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:02:47 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:05:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rgb.h"
# include "vector.h"

typedef struct s_light	t_light;

struct s_light
{
	double		brightness;
	t_rgb		color;
	t_vector	pos;
};

#endif
