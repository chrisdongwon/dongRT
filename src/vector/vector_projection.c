/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:57:39 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 11:58:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_projection(t_vector v, t_vector dir)
{
	return (scalar_multiplication(dot_product(v, dir), dir));
}
