/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:39:47 by cwon              #+#    #+#             */
/*   Updated: 2025/11/04 15:53:18 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

#include "libft.h"
#include "parser.h"

static const char	*get_identifier(t_parser *p)
{
	return ((const char *)p->list->content);
}

void	dispatch_subparser(t_parser *p)
{
	const char	*id;
	size_t		i;

	id = get_identifier(p);
	i = 0;
	while (p->subparser[i].id)
	{
		if (ft_strcmp(id, p->subparser[i].id) == 0)
			return ((p->subparser[i].fn)(p));
		i++;
	}
	parser_error(p, id, "Unknown identifier");
}
