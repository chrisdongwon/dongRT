/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:44:26 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 14:03:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

#include <math.h>

int rgba_to_int(t_color c, double a)
{
    int A = (int)(fmin(fmax(a, 0), 1) * 255);
    int R = (int)(fmin(fmax(c.r, 0), 1) * 255);
    int G = (int)(fmin(fmax(c.g, 0), 1) * 255);
    int B = (int)(fmin(fmax(c.b, 0), 1) * 255);

    return (A << 24) | (R << 16) | (G << 8) | B;
}
