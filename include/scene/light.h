/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:39:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 12:59:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "vector.h"

typedef struct s_light	t_light;

struct s_light
{
	double		brightness;
	t_color		color;
	t_vector	pos;
};

#endif
