/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:52:50 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 14:40:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

#include <math.h>

t_basis	camera_basis(t_vector dir)
{
	t_basis		basis;
	t_vector	up;

	basis.forward = normalize(dir);
	if (fabs(basis.forward.y) > 0.999)
		up = (t_vector){0.0, 0.0, 1.0};
	else
		up = (t_vector){0.0, 1.0, 0.0};
	basis.right = normalize(cross(up, basis.forward));
	basis.up = normalize(cross(basis.forward, basis.right));
	return (basis);
}
