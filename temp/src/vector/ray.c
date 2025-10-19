/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:55:22 by cwon              #+#    #+#             */
/*   Updated: 2025/09/17 16:56:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vector	ray_at(t_ray *r, double t)
{
	return (vector_addition(r->origin, scalar_multiplication(t, r->dir)));
}
