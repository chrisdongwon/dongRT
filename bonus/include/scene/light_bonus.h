/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:39:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:41:43 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_BONUS_H
# define LIGHT_BONUS_H

# include "color_bonus.h"
# include "vector_bonus.h"

typedef struct s_light	t_light;

struct s_light
{
	double		brightness;
	t_color		color;
	t_vector	pos;
};

#endif
