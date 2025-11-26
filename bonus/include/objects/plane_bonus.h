/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:06:40 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:41:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_BONUS_H
# define PLANE_BONUS_H

# include "vector_bonus.h"

typedef struct s_plane	t_plane;

struct s_plane
{
	t_vector	normal;
	t_vector	point;
};

#endif
