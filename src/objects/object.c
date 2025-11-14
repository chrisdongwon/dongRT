/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:46:07 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 13:19:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include <stdlib.h>

#include "libft.h"
#include "mini_rt.h"
#include "parser.h"
#include "scene.h"

static	t_list	*new_obj_node(t_parser *p, t_object *obj)
{
	t_list	*node;

	node = ft_lstnew(obj);
	if (node == NULL)
	{
		free_object(obj);
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	return (node);
}

static	t_object	*new_object(t_parser *p, void *ptr, t_obj_type t, t_color c)
{
	t_object	*obj;

	obj = parser_malloc(p, sizeof(t_object));
	obj->color = c;
	obj->ptr = ptr;
	obj->type = t;
	return (obj);
}

void	append_object(t_parser *p, void *shape, t_obj_type t, t_color c)
{
	t_object	*obj;
	t_list		*node;

	obj = new_object(p, shape, t, c);
	node = new_obj_node(p, obj);
	ft_lstadd_back(&p->scene->objects, node);
}

void	free_object(void *ptr)
{
	t_object	*obj;

	if (ptr != NULL)
	{
		obj = (t_object *)ptr;
		free(obj->ptr);
		free(ptr);
	}
}
