/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:46:49 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:09:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

#include <stdio.h>

void	print_cylinder(void *ptr)
{
	t_cylinder	*c;

	c = (t_cylinder *)ptr;
	printf("  Cylinder: center=");
	print_vector(&c->pos);
	printf(", axis=");
	print_vector(&c->dir);
	printf(", diameter=%.2f, height=%.2f, color=", c->diameter, c->height);
	print_rgb(&c->color);
	printf("\n");
}
