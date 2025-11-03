/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:07:41 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 15:17:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vector.h"

typedef struct s_cylinder	t_cylinder;

// how to represent infinite cylinder?
// is height positive or nonnegative?
// is radius positive or nonnegative?
// dir is normalized
struct s_cylinder
{
	double		height;
	double		radius;
	t_vector	center;
	t_vector	dir;
};

#endif
