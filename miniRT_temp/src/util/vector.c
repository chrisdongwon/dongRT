/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:33:52 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 22:34:51 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_add(t_vector u, t_vector v)
{
	return (vector(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vector	vector_scale(double c, t_vector v)
{
	return (vector(c * v.x, c * v.y, c * v.z));
}

t_vector	vector_sub(t_vector u, t_vector v)
{
	return (vector(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vector	vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
