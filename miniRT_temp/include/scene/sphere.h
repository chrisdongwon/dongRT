/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:35:05 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 15:44:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vector.h"
# include "color.h"

typedef struct s_sphere	t_sphere;

struct s_sphere
{
	double		radius;
	t_color		color;
	t_vector	center;
};

#endif
