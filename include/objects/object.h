/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:02:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/10 14:07:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "color.h"
# include "ray.h"

typedef enum e_obj_type	t_obj_type;
typedef struct s_hit	t_hit;
typedef struct s_object	t_object;
typedef bool			(*t_hit_fn)(t_object *obj, t_ray ray, t_hit *hit);
typedef struct s_parser	t_parser;

enum e_obj_type
{
	CYLINDER,
	PLANE,
	SPHERE
};

struct s_object
{
	t_color		color;
	t_hit_fn	hit_fn;
	t_obj_type	type;
	void		*ptr;
};

// object.c
void	append_object(t_parser *p, void *elem, t_obj_type t, t_color c);
void	free_object(void *ptr);

#endif
