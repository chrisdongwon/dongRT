/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:41:52 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 15:06:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "color.h"
# include "vector.h"

typedef struct s_sphere	t_sphere;

// is radius positive or nonnegative?
struct s_sphere
{
	double		radius;
	t_vector	center;
};

#endif
