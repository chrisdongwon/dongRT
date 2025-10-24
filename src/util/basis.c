/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:31 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 13:01:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

#include <math.h>

t_basis	basis(t_vector i, t_vector k)
{
	t_basis	b;

	b.i = normalize(i);
	if (fabs(dot_prod(i, k)) > 0.999)
		k = vector(0.0, 0.0, 1.0);
	b.j = normalize(cross_prod(b.i, k));
	b.k = cross_prod(b.j, b.i);
	return (b);
}
