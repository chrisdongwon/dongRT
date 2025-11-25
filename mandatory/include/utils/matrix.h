/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:44:16 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 14:49:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_basis	t_basis;
typedef struct s_matrix	t_matrix;
typedef struct s_vector	t_vector;

struct s_matrix
{
	double	m[4][4];
};

// matrix_transform.c
t_vector	transform(const t_matrix *mat, const t_vector *u, bool translate);

// matrix.c
t_matrix	basis_matrix(const t_basis *b, bool invert_z);
t_matrix	id_matrix(void);
t_matrix	matrix_prod(const t_matrix *a, const t_matrix *b);
t_matrix	translate_matrix(const t_vector *v);

#endif
