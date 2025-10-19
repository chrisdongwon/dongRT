/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:29:34 by cwon              #+#    #+#             */
/*   Updated: 2025/09/17 16:44:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadratic.h"

#include <math.h>

static void	swap(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

bool	solve_quadratic(double a, double b, double c, t_quadratic *out)
{
	double	disc;
	double	q;
	double	sqrt_disc;

	disc = discriminant(a, b, c);
	if (disc < 0.0)
		return (false);
	sqrt_disc = sqrt(disc);
	if (b > 0)
		q = -0.5 * (b + sqrt_disc);
	else
		q = -0.5 * (b - sqrt_disc);
	out->t0 = q / a;
	out->t1 = c / q;
	if (out->t0 > out->t1)
		swap(&out->t0, &out->t1);
	return (true);
}

double	smallest_positive_root(t_quadratic *roots)
{
	if (roots->t0 > EPSILON)
		return (roots->t0);
	if (roots->t1 > EPSILON)
		return (roots->t1);
	return (-1.0);
}

double	discriminant(double a, double b, double c)
{
	return (b * b - 4.0 * a * c);
}
