/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:31 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 13:35:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

#include <math.h>

t_basis	basis(t_vector forward, t_vector up)
{
	t_basis	b;

	b.i = normalize(forward);
	if (fabs(dot_prod(forward, up)) > 0.999)
		up = vector(0.0, 0.0, 1.0);
	b.j = normalize(cross_prod(b.i, up));
	b.k = cross_prod(b.j, b.i);
	return (b);
}
