/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:29:02 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 08:07:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_info.h"

t_light_info	light_info(t_vector dir, t_color color, double shadow)
{
	t_light_info	l;

	l.dir = normalize(dir);
	l.color = color;
	l.shadow = shadow;
	return (l);
}
