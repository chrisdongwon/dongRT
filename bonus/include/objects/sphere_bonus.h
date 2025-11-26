/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:41:52 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 14:17:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_BONUS_H
# define SPHERE_BONUS_H

# include "color_bonus.h"
# include "vector_bonus.h"

typedef struct s_sphere	t_sphere;

struct s_sphere
{
	double		radius;
	t_vector	center;
};

#endif
