/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:02:24 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 17:56:41 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <math.h>

bool	is_normalized(t_vector v)
{
	return (fabs(norm(v) - 1.0) < 1e-2);
}

double	norm(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	normalize(t_vector v)
{
	return (scale(1.0 / norm(v), v));
}
