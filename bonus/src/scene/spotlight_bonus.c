/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:41:24 by cwon              #+#    #+#             */
/*   Updated: 2026/03/01 14:16:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spotlight_bonus.h"

#include <math.h>
#include <stdlib.h>

#include "hit_bonus.h"
#include "libft.h"
#include "mini_rt_bonus.h"
#include "parser_bonus.h"
#include "scene_bonus.h"

static	t_list	*new_spotlight_node(t_parser *p, t_spotlight *s)
{
	t_list	*node;

	node = ft_lstnew(s);
	if (node == NULL)
	{
		free(s);
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	return (node);
}

bool	in_spotlight(const t_hit *h, const t_spotlight *s)
{
	t_vector	v;

	v = normalize(subtract(h->point, s->pos));
	return (dot(v, s->dir) > cos(M_PI / 6.0));
}

void	append_spotlight(t_parser *p, t_spotlight *s)
{
	t_list	*node;

	node = new_spotlight_node(p, s);
	ft_lstadd_back(&p->scene->spotlights, node);
}
