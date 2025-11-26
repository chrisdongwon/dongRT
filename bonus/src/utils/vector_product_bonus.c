/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:37:17 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:45:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

double	dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector	cross(t_vector u, t_vector v)
{
	t_vector	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	return (result);
}
