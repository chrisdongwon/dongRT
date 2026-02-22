/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:34:56 by cwon              #+#    #+#             */
/*   Updated: 2026/02/22 16:39:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

# define EPS_NORM 1e-4

# include <stdbool.h>

typedef struct s_point	t_point;
typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

// vector_norm_bonus.c
bool		is_normalized(t_vector v);
double		norm(t_vector v);
t_vector	normalize(t_vector v);

// vector_product_bonus.c
double		dot(t_vector u, t_vector v);
t_vector	cross(t_vector u, t_vector v);

// vector_projection_bonus.c
t_vector	perp(t_vector u, t_vector v);

// vector_bonus.c
t_vector	add(t_vector u, t_vector v);
t_vector	reflect(t_vector v, t_vector n);
t_vector	scale(double c, t_vector v);
t_vector	subtract(t_vector u, t_vector v);

#endif
