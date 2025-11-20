/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:44:18 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 15:36:22 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadratic.h"

#include <math.h>

#include "libft.h"

static void	init_quadratic(t_quadratic *q)
{
	ft_memset(q, 0, sizeof(*q));
}

static void	swap(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	min_positive_root(const t_quadratic *q)
{
	if (q->t1 > 1e-6 && q->t2 > 1e-6)
		return (q->t1);
	if (q->t1 > 1e-6)
		return (q->t1);
	if (q->t2 > 1e-6)
		return (q->t2);
	return (-1.0);
}

t_quadratic	solve_quadratic(double abc[3])
{
	double		discriminant;
	double		sqrt_disc;
	t_quadratic	q;

	init_quadratic(&q);
	discriminant = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (discriminant < 0)
		return (q);
	sqrt_disc = sqrt(discriminant);
	q.t1 = (-abc[1] - sqrt_disc) / (2.0 * abc[0]);
	q.t2 = (-abc[1] + sqrt_disc) / (2.0 * abc[0]);
	if (q.t1 > q.t2)
		swap(&q.t1, &q.t2);
	q.real_roots = true;
	return (q);
}
