/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:22:36 by cwon              #+#    #+#             */
/*   Updated: 2025/09/15 16:32:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <math.h>

double	norm(t_vector v)
{
	return (sqrt(dot_product(v, v)));
}

t_vector	normalize(t_vector v)
{
	double		len;
	t_vector	result;

	len = norm(v);
	result = vector(0, 0, 0);
	if (len > 1e-8)
	{
		result.x = v.x / len;
		result.y = v.y / len;
		result.z = v.z / len;
	}
	return (result);
}
