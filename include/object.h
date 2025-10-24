/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:38:37 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 14:51:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "material.h"

typedef enum e_obj_type	t_obj_type;
typedef struct s_object	t_object;

enum e_obj_type
{
	CYLINDER_OBJ,
	PLANE_OBJ,
	SPHERE_OBJ
};

struct s_object
{
	t_material	mat;
	t_obj_type	type;
	void		*shape; // pointer to sphere/plane/cylinder
};

// object.c
void	flush_object(void *ptr);

#endif
