/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:39:47 by cwon              #+#    #+#             */
/*   Updated: 2025/11/05 15:07:25 by cwon             ###   ########.fr       */
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
	size_t	i;

	p->id = get_identifier(p);
	i = 0;
	while (p->subparser[i].id)
	{
		if (ft_strcmp(p->id, p->subparser[i].id) == 0)
			return ((p->subparser[i].fn)(p));
		i++;
	}
	parser_error(p, "Unknown identifier");
}
