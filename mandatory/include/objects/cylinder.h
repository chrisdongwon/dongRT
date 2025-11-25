/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:07:41 by cwon              #+#    #+#             */
/*   Updated: 2025/11/21 12:21:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vector.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	double		height;
	double		radius;
	t_vector	axis;
	t_vector	center;
};

#endif
