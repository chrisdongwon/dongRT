/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:35 by cwon              #+#    #+#             */
/*   Updated: 2025/09/17 16:41:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRATIC_H
# define QUADRATIC_H

# define EPSILON 1e-6

# include <stdbool.h>

typedef struct s_quadratic	t_quadratic;

struct s_quadratic
{
	double	t0;
	double	t1;
};

bool	solve_quadratic(double a, double b, double c, t_quadratic *out);
double	smallest_positive_root(t_quadratic *roots);
double	discriminant(double a, double b, double c);

#endif
