/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:41:01 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 15:36:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRATIC_H
# define QUADRATIC_H

# include <stdbool.h>

typedef struct s_quadratic	t_quadratic;

struct s_quadratic
{
	bool	real_roots;
	double	t1;
	double	t2;
};

// quadratic.c
double		min_positive_root(const t_quadratic *q);
t_quadratic	solve_quadratic(double abc[3]);

#endif
