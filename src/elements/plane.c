/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:45:02 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 08:57:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

#include <stdio.h>

#include "rgb.h"
#include "vector.h"

void	print_plane(void *ptr)
{
	t_plane	*p;

	p = (t_plane *)ptr;
	printf("  Plane: point=");
	print_vector(&p->pos);
	printf(", normal=");
	print_vector(&p->normal);
	printf(", color=");
	print_rgb(&p->color);
	printf("\n");
}
