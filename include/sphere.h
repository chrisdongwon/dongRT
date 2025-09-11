/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:06:45 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:06:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "rgb.h"
# include "vector.h"

typedef struct s_sphere	t_sphere;

struct s_sphere
{
	double		diameter;
	t_rgb		color;
	t_vector	center;
};

void	print_sphere(void *ptr);

#endif
