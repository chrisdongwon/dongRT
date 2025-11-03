/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:34:25 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 22:39:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_clamp(t_vector v, double min, double max)
{
	if (v.x < min)
		v.x = min;
	else if (v.x > max)
		v.x = max;
	if (v.y < min)
		v.y = min;
	else if (v.y > max)
		v.y = max;
	if (v.z < min)
		v.z = min;
	else if (v.z > max)
		v.z = max;
	return (v);
}

t_vector	vector_reflect(t_vector v, t_vector n)
{
	double	proj;

	proj = dot_prod(v, n);
	return (vector_sub(v, vector_scale(2.0 * proj, n)));
}
