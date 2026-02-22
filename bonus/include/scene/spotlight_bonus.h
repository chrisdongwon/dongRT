/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:30:53 by cwon              #+#    #+#             */
/*   Updated: 2026/02/22 16:31:34 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOTLIGHT_BONUS_H
# define SPOTLIGHT_BONUS_H

# include "color_bonus.h"
# include "vector_bonus.h"

typedef struct s_spotlight	t_spotlight;

struct s_spotlight
{
	double		brightness;
	t_color		color;
	t_vector	dir;
	t_vector	pos;
};

#endif
