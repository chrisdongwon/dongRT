/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:44:49 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 11:44:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "ray.h"

void	reorient_normal(t_ray *ray, t_vector outward_normal, t_hit *record)
{
	record->is_front = dot_product(ray->dir, outward_normal) < 0;
	record->normal = outward_normal;
	if (!record->is_front)
		record->normal = scalar_multiplication(-1, outward_normal);
}
