/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:44:43 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 14:22:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include <stdlib.h>

void	flush_object(void *ptr)
{
	t_object	*obj;

	if (ptr != NULL)
	{
		obj = (t_object *)ptr;
		free(obj->ptr);
	}
}
