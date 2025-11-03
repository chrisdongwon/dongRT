/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:26:25 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 00:23:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>

# include "vector.h"

typedef struct s_matrix	t_matrix;

struct s_matrix
{
	double	m[4][4];
};

// matrix_product.c
t_matrix	mat_mat_prod(const t_matrix *a, const t_matrix *b);
t_vector	mat_vec_prod(const t_matrix *m, t_vector v, bool translate);

// matrix.c
t_matrix	basis_mat(t_vector b1, t_vector b2, t_vector b3, t_vector pos);
t_matrix	identity_mat(void);
t_matrix	scale_mat(double sx, double sy, double sz);
t_matrix	translate_mat(double tx, double ty, double tz);

#endif
