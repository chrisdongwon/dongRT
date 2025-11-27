/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:59:17 by cwon              #+#    #+#             */
/*   Updated: 2025/11/27 15:02:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_BONUS_H
# define PARABOLOID_BONUS_H

# include "vector_bonus.h"

typedef struct s_paraboloid	t_paraboloid;

struct s_paraboloid
{
	double		height;
	double		k;
	t_vector	center;
	t_vector	normal;
};

#endif
