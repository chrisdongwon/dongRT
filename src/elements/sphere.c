/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:41:25 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 08:57:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

#include <stdio.h>

#include "rgb.h"
#include "vector.h"

void	print_sphere(void *ptr)
{
	t_sphere	*s;

	s = (t_sphere *)ptr;
	printf("  Sphere: center=");
	print_vector(&s->center);
	printf(", diameter=%.2f, color=", s->diameter);
	print_rgb(&s->color);
	printf("\n");
}
