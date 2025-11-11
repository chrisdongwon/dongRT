/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:13:12 by cwon              #+#    #+#             */
/*   Updated: 2025/11/11 13:46:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	add(t_vector u, t_vector v)
{
	t_vector	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vector	reflect(t_vector v, t_vector normal)
{
	return (subtract(v, scale(2.0 * dot(v, normal), normal)));
}

t_vector	scale(double c, t_vector v)
{
	v.x = c * v.x;
	v.y = c * v.y;
	v.z = c * v.z;
	return (v);
}

t_vector	subtract(t_vector u, t_vector v)
{
	t_vector	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}
