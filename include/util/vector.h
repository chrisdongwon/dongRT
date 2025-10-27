/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:17:28 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 22:41:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

// vector_normalize.c
double		vector_norm(t_vector v);
t_vector	normalize(t_vector v);

// vector_product.c
double		dot_prod(t_vector u, t_vector v);
t_vector	cross_prod(t_vector u, t_vector v);

// vector_transform.c
t_vector	vector_clamp(t_vector v, double min, double max);
t_vector	vector_reflect(t_vector v, t_vector n);

// vector.c
t_vector	vector_add(t_vector u, t_vector v);
t_vector	vector_scale(double c, t_vector v);
t_vector	vector_sub(t_vector u, t_vector v);
t_vector	vector(double x, double y, double z);

#endif
