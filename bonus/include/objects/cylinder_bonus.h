/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:07:41 by cwon              #+#    #+#             */
/*   Updated: 2025/12/01 08:50:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_BONUS_H
# define CYLINDER_BONUS_H

# include "vector_bonus.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	double		height;
	double		radius;
	t_vector	axis;
	t_vector	center;
};

#endif
