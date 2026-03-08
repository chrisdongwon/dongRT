/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:43:26 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 15:45:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

#include "camera.h"
#include "mini_rt.h"

t_point	init_ndc(double px, double py)
{
	t_point	ndc;

	ndc.x = (px + 0.5) / (double)WIDTH;
	ndc.y = (py + 0.5) / (double)HEIGHT;
	return (ndc);
}

void	ndc_to_ssc(t_point *p)
{
	p->x = 2.0 * p->x - 1.0;
	p->y = 1.0 - 2.0 * p->y;
}
