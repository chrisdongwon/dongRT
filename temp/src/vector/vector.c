/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:41:06 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:50:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <stdio.h>

t_vector	vector(double x, double y, double z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vector	vector_addition(t_vector v1, t_vector v2)
{
	return (vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector	vector_subtraction(t_vector v1, t_vector v2)
{
	return (vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector	scalar_multiplication(double c, t_vector vec)
{
	return (vector(c * vec.x, c * vec.y, c * vec.z));
}

void	print_vector(t_vector *vec)
{
	printf("(%.2f, %.2f, %.2f)", vec->x, vec->y, vec->z);
}
