/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:52:47 by cwon              #+#    #+#             */
/*   Updated: 2025/10/09 13:23:22 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIS_H
# define BASIS_H

# include "vector.h"

typedef struct s_basis	t_basis;

struct s_basis
{
	t_vector	u;
	t_vector	v;
	t_vector	w;
};

#endif
