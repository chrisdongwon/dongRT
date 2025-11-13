/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:46:58 by cwon              #+#    #+#             */
/*   Updated: 2025/11/13 13:49:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

t_basis	init_basis(t_vector forward)
{
	const double	epsilon = 1e-6;
	const t_vector	alt_up = {0.0, 0.0, 1.0};
	const t_vector	world_up = {0.0, 1.0, 0.0};
	t_basis			basis;

	basis.forward = forward;
	basis.right = normalize(cross(basis.forward, world_up));
	if (norm(basis.right) < epsilon)
		basis.right = normalize(cross(basis.forward, alt_up));
	basis.up = normalize(cross(basis.right, basis.forward));
	return (basis);
}
