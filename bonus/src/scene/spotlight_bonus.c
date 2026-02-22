/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:41:24 by cwon              #+#    #+#             */
/*   Updated: 2026/02/22 16:50:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spotlight_bonus.h"

#include <stdlib.h>

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

void	append_spotlight(t_parser *p, t_spotlight *s)
{
	t_list	*node;

	node = new_spotlight_node(p, s);
	ft_lstadd_back(&p->scene->spotlights, node);
}
