/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:24:37 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 20:25:59 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "surface.h"

t_surface	surface(t_material mat, t_vector normal, t_vector hit_point)
{
	t_surface	s;

	s.mat = mat;
	s.normal = normalize(normal);
	s.hit_point = hit_point;
	return (s);
}
