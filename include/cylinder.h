/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:36:59 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 16:38:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vector.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	t_vector	base; // bottom center
	t_vector	axis; // normalized
	double		radius;
	double		height; // 0 if infinite
};

#endif
