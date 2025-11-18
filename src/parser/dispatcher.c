/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:39:47 by cwon              #+#    #+#             */
/*   Updated: 2025/11/17 10:13:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

#include "libft.h"
#include "parser.h"

static const char	*get_identifier(t_parser *const p)
{
	return ((const char *)p->list->content);
}

t_hit_fn	get_hit_fn(t_parser *const p)
{
	size_t	i;

	p->id = get_identifier(p);
	i = 0;
	while (p->dispatcher[i].id)
	{
		if (ft_strcmp(p->id, p->dispatcher[i].id) == 0)
			return (p->dispatcher[i].hit_fn);
		i++;
	}
	parser_error(p, "Unknown identifier");
	return (NULL);
}

void	dispatch_subparser(t_parser *const p)
{
	size_t	i;

	p->id = get_identifier(p);
	i = 0;
	while (p->dispatcher[i].id)
	{
		if (ft_strcmp(p->id, p->dispatcher[i].id) == 0)
			return((p->dispatcher[i].parse_fn)(p));
		i++;
	}
	parser_error(p, "Unknown identifier");
}
