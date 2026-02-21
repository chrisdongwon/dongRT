/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_projection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:59:27 by cwon              #+#    #+#             */
/*   Updated: 2026/02/21 14:37:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

static t_vector	proj(t_vector u, t_vector v)
{
	double	norm_sq;

	norm_sq = dot(v, v);
	if (norm_sq < EPS_NORM)
		return ((t_vector){0, 0, 0});
	return (scale(dot(u, v) / norm_sq, v));
}

t_vector	perp(t_vector u, t_vector v)
{
	return (subtract(u, proj(u, v)));
}
