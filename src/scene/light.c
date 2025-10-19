/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:52:21 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 15:00:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

#include <stdlib.h>

#include "libft.h"

t_light	*new_light(t_light_type type, t_vector v, t_color c, double intensity)
{
	t_light	*l;

	l = malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->type = type;
	l->pos = v;
	l->color = c;
	l->intensity = intensity;
	return (l);
}
