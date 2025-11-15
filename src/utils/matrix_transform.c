/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:27:46 by cwon              #+#    #+#             */
/*   Updated: 2025/11/15 12:17:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	apply_translation(const t_matrix *const mat,
const t_vector *const u, t_vector *const v)
{
	double	w;

	w = mat->m[3][0] * u->x + mat->m[3][1] * u->y + mat->m[3][2] * u->z;
	v->x += mat->m[0][3];
	v->y += mat->m[1][3];
	v->z += mat->m[2][3];
	w += mat->m[3][3];
	if (w != 0.0 && w != 1.0)
	{
		v->x /= w;
		v->y /= w;
		v->z /= w;
	}
}

t_vector	transform(const t_matrix *const mat, const t_vector *const u,
bool translate)
{
	t_vector	v;

	v.x = mat->m[0][0] * u->x + mat->m[0][1] * u->y + mat->m[0][2] * u->z;
	v.y = mat->m[1][0] * u->x + mat->m[1][1] * u->y + mat->m[1][2] * u->z;
	v.z = mat->m[2][0] * u->x + mat->m[2][1] * u->y + mat->m[2][2] * u->z;
	if (translate)
		apply_translation(mat, u, &v);
	return (v);
}
