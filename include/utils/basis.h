/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:50:10 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 14:00:47 by cwon             ###   ########.fr       */
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
t_basis	camera_basis(t_vector dir);

#endif
