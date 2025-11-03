/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:46:07 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 21:47:31 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include <stdlib.h>

void	free_object(void *ptr)
{
	t_object	*obj;

	if (ptr != NULL)
	{
		obj = (t_object *)ptr;
		free(obj->element);
		free(ptr);
	}
}
