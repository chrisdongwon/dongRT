/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:50:20 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 11:48:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

#include "basis.h"
#include "libft.h"

static t_matrix	zero_matrix(void)
{
	t_matrix	mat;

	ft_memset(&mat, 0, sizeof(t_matrix));
	return (mat);
}

t_matrix	basis_matrix(const t_basis *const b, bool invert_z)
{
	double		dir;
	t_matrix	mat;

	dir = -2.0 * invert_z + 1.0;
	mat = id_matrix();
	mat.m[0][0] = b->right.x;
	mat.m[0][1] = b->right.y;
	mat.m[0][2] = b->right.z;
	mat.m[1][0] = b->up.x;
	mat.m[1][1] = b->up.y;
	mat.m[1][2] = b->up.z;
	mat.m[2][0] = dir * b->forward.x;
	mat.m[2][1] = dir * b->forward.y;
	mat.m[2][2] = dir * b->forward.z;
	return (mat);
}

t_matrix	id_matrix(void)
{
	t_matrix	mat;

	ft_memset(&mat, 0, sizeof(t_matrix));
	mat.m[0][0] = 1.0;
	mat.m[1][1] = 1.0;
	mat.m[2][2] = 1.0;
	mat.m[3][3] = 1.0;
	return (mat);
}

t_matrix	matrix_prod(const t_matrix *const a, const t_matrix *const b)
{
	t_matrix	mat;
	size_t		i;
	size_t		j;
	size_t		k;

	mat = zero_matrix();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				mat.m[i][j] += a->m[i][k] * b->m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (mat);
}

t_matrix	translate_matrix(const t_vector *const v)
{
	t_matrix	mat;

	mat = id_matrix();
	mat.m[0][3] = v->x;
	mat.m[1][3] = v->y;
	mat.m[2][3] = v->z;
	return (mat);
}
