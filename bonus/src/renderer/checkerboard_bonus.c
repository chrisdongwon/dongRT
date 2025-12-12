/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:37 by cwon              #+#    #+#             */
/*   Updated: 2025/12/12 15:36:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

int checker_plane(const t_vector p, double scale)
{
	int	x;
	int	y;
	int	z;

	x = floor(p.x * scale);
	y = floor(p.y * scale);
	z = floor(p.z * scale);
	return ((x + y + z) % 2 != 0);
}
