/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:56:19 by cwon              #+#    #+#             */
/*   Updated: 2025/09/15 16:42:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

// vector_norm.c
double		norm(t_vector v);
t_vector	normalize(t_vector v);

// vector_product.c
double		dot_product(t_vector v1, t_vector v2);
t_vector	cross_product(t_vector v, t_vector w);

//	vector.c
t_vector	vector(double x, double y, double z);
t_vector	vector_addition(t_vector v1, t_vector v2);
t_vector	vector_subtraction(t_vector v1, t_vector v2);
t_vector	scalar_multiplication(double c, t_vector vec);
void		print_vector(t_vector *vec);

#endif
