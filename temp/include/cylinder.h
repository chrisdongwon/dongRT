/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:36:58 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 11:30:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "rgb.h"
# include "vector.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	double		diameter;
	double		height;
	t_rgb		color;
	t_vector	dir;
	t_vector	pos;
};

void	print_cylinder(void *ptr);

#endif
