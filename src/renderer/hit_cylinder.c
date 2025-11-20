/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:49:44 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 15:33:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

#include "object.h"

t_hit	hit_cylinder(const t_ray *r, const t_object *obj)
{
	t_hit	hit;

	init_hit(&hit);
	(void)r;
	(void)obj;
	return (hit);
}
