/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:37:02 by cwon              #+#    #+#             */
/*   Updated: 2025/09/19 10:52:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interval.h"

bool	in_interval(double t, t_interval range)
{
	return (range.min <= t && t <= range.max);
}

double	closest_root_in_range(t_quadratic solution, t_interval range)
{
	if (solution.t0 < range.min || solution.t0 > range.max)
		return (solution.t1);
	return (solution.t0);
}
