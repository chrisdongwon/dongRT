/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:26:16 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 13:35:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIS_H
# define BASIS_H

# include "vector.h"

typedef struct s_basis	t_basis;

struct s_basis
{
	t_vector	i;
	t_vector	j;
	t_vector	k;
};

// basis.c
t_basis	basis(t_vector forward, t_vector up);

#endif
