/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:51:01 by cwon              #+#    #+#             */
/*   Updated: 2025/09/15 16:57:18 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	cross_product(t_vector v, t_vector w)
{
	return (vector(v.y * w.z - v.z * w.y, v.z * w.x - v.x * w.z, \
v.x * w.y - v.y * w.x));
}
