/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:27:46 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 22:36:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <math.h>

double	vector_norm(t_vector v)
{
	return (sqrt(dot_prod(v, v)));
}

t_vector	normalize(t_vector v)
{
	double	len;

	len = vector_norm(v);
	if (len == 0.0)
		return (vector(0.0, 0.0, 0.0));
	return (vector_scale(1.0 / len, v));
}
