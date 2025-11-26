/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:08:22 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 14:14:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIS_BONUS_H
# define BASIS_BONUS_H

# include "vector_bonus.h"

typedef struct s_basis	t_basis;

struct s_basis
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
};

// basis.c
t_basis	init_basis(t_vector forward);

#endif
