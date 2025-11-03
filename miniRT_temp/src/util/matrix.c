/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:50:18 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 00:13:34 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

#include "libft.h"

t_matrix	basis_mat(t_vector b1, t_vector b2, t_vector b3, t_vector pos)
{
	t_matrix	mat;

	mat = identity_mat();
	mat.m[0][0] = b1.x;
	mat.m[0][1] = b2.x;
	mat.m[0][2] = b3.x;
	mat.m[0][3] = pos.x;
	mat.m[1][0] = b1.y;
	mat.m[1][1] = b2.y;
	mat.m[1][2] = b3.y;
	mat.m[1][3] = pos.y;
	mat.m[2][0] = b1.z;
	mat.m[2][1] = b2.z;
	mat.m[2][2] = b3.z;
	mat.m[2][3] = pos.z;
	return (mat);
}

t_matrix	identity_mat(void)
{
	t_matrix	mat;

	ft_memset(&mat, 0, sizeof(t_matrix));
	mat.m[0][0] = 1.0;
	mat.m[1][1] = 1.0;
	mat.m[2][2] = 1.0;
	mat.m[3][3] = 1.0;
	return (mat);
}

t_matrix	scale_mat(double sx, double sy, double sz)
{
	t_matrix	mat;

	mat = identity_mat();
	mat.m[0][0] = sx;
	mat.m[1][1] = sy;
	mat.m[2][2] = sz;
	return (mat);
}

t_matrix	translate_mat(double tx, double ty, double tz)
{
	t_matrix	mat;

	mat = identity_mat();
	mat.m[0][3] = tx;
	mat.m[1][3] = ty;
	mat.m[2][3] = tz;
	return (mat);
}
