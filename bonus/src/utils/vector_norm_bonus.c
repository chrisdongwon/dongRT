/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:02:24 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:45:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

#include <math.h>

bool	is_normalized(t_vector v)
{
	return (fabs(norm(v) - 1.0) < EPSILON);
}

double	norm(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	normalize(t_vector v)
{
	return (scale(1.0 / norm(v), v));
}
