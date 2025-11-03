/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:52:21 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 07:31:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

#include <stdlib.h>

#include "libft.h"

t_light	*new_light(t_vector v, t_color c, double intensity)
{
	t_light	*l;

	l = malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = v;
	l->color = c;
	l->intensity = intensity;
	return (l);
}
