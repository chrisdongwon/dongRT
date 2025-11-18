/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:27:46 by cwon              #+#    #+#             */
/*   Updated: 2025/11/17 11:04:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void apply_translation(const t_matrix *const mat, t_vector *v)
{
	v->x += mat->m[0][3];
	v->y += mat->m[1][3];
	v->z += mat->m[2][3];
}

t_vector	transform(const t_matrix *const mat, const t_vector *const u,
bool translate)
{
	t_vector	v;

	v.x = u->x * mat->m[0][0] + u->y * mat->m[0][1] + u->z * mat->m[0][2];
	v.y = u->x * mat->m[1][0] + u->y * mat->m[1][1] + u->z * mat->m[1][2];
	v.z = u->x * mat->m[2][0] + u->y * mat->m[2][1] + u->z * mat->m[2][2];
	if (translate)
		apply_translation(mat, &v);
	return (v);
}
