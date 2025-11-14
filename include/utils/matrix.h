/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:44:16 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 10:17:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>

typedef struct s_basis	t_basis;
typedef struct s_matrix	t_matrix;
typedef struct s_vector	t_vector;

struct s_matrix
{
	double	m[4][4];
};

// matrix.c
t_matrix	basis_matrix(t_basis *b, bool invert_z);
t_matrix	id_matrix(void);
t_matrix	matrix_prod(t_matrix *a, t_matrix *b);
t_matrix	translate_matrix(t_vector *v);

#endif
