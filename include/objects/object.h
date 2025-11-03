/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:02:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 15:17:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "color.h"

typedef enum e_obj_type	t_obj_type;
typedef struct s_object	t_object;

enum e_obj_type
{
	OBJ_CYLINDER,
	OBJ_PLANE,
	OBJ_SPHERE
};

struct s_object
{
	t_color		color;
	t_obj_type	type;
	void		*element;
};

#endif
