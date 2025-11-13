/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:08:22 by cwon              #+#    #+#             */
/*   Updated: 2025/11/13 13:47:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIS_H
# define BASIS_H

# include "vector.h"

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
