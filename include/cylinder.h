/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:36:58 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 08:49:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "rgb.h"
# include "vector.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	float		diameter;
	float		height;
	t_rgb		color;
	t_vector	dir;
	t_vector	pos;
};

void	print_cylinder(void *ptr);

#endif
