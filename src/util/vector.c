/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:41:06 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 07:51:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <stdio.h>

#include "libft.h"

bool	is_normed(t_vector *vec)
{
	return (ft_isbetween(vec->x, -1.0, 1.0) && \
ft_isbetween(vec->y, -1.0, 1.0) && ft_isbetween(vec->z, -1.0, 1.0));
}

void	print_vector(t_vector *vec)
{
	printf("(%.2f, %.2f, %.2f)", vec->x, vec->y, vec->z);
}
