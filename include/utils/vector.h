/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:34:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/21 09:57:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define EPSILON 1e-6

# include <stdbool.h>

typedef struct s_point	t_point;
typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

// vector_norm.c
bool		is_normalized(t_vector v);
double		norm(t_vector v);
t_vector	normalize(t_vector v);

// vector_product.c
double		dot(t_vector u, t_vector v);
t_vector	cross(t_vector u, t_vector v);

// vector.c
t_vector	add(t_vector u, t_vector v);
t_vector	scale(double c, t_vector v);
t_vector	subtract(t_vector u, t_vector v);

#endif
