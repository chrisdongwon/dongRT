/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:02:22 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 15:40:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	default_material(void)
{
	t_material	m;

	m.color = color(0.8, 0.8, 0.8);
	m.diffuse = 0.9;
	m.specular = 0.5;
	m.shininess = 64.0;
	m.reflection = 0.0;
	m.refraction = 0.0;
	m.ior = 1.0;
	return (m);
}
