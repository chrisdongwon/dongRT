/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:48:32 by cwon              #+#    #+#             */
/*   Updated: 2025/11/10 14:33:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadratic.h"

#include <math.h>

static double	discriminant(const double abc[3])
{
	return (abc[1] * abc[1] - 4.0 * abc[0] * abc[2]);
}

bool	solve_quadratic(const double abc[3], double *t)
{
	double	disc;
	double	sqrt_disc;
	double	soln[2];

	disc = discriminant(abc);
	if (disc < 0.0)
		return (false);
	sqrt_disc = sqrt(disc);
	soln[0] = (-abc[1] - sqrt_disc) / (2.0 * abc[0]);
	soln[1] = (-abc[1] + sqrt_disc) / (2.0 * abc[0]);
	if (soln[0] >= 0.0)
		*t = soln[0];
	else if (soln[1] >= 0.0)
		*t = soln[1];
	else
		return (false);
	return (true);
}
