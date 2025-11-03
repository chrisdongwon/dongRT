/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:07:51 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 00:23:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

#include "libft.h"

t_matrix	mat_mat_prod(const t_matrix *a, const t_matrix *b)
{
	int			i;
	int			j;
	int			k;
	t_matrix	res;

	i = 0;
	j = 0;
	k = 0;
	ft_memset(&res, 0, sizeof(t_matrix));
	while (i < 4)
	{
		while (j < 4)
		{
			while (k < 4)
			{
				res.m[i][j] += a->m[i][k] * b->m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

t_vector	mat_vec_prod(const t_matrix *m, t_vector v, bool translate)
{
	t_vector	res;

	res.x = m->m[0][0] * v.x + m->m[0][1] * v.y + m->m[0][2] * v.z + \
m->m[0][3] * (double)translate;
	res.y = m->m[1][0] * v.x + m->m[1][1] * v.y + m->m[1][2] * v.z + \
m->m[1][3] * (double)translate;
	res.z = m->m[2][0] * v.x + m->m[2][1] * v.y + m->m[2][2] * v.z + \
m->m[2][3] * (double)translate;
	return (res);
}
