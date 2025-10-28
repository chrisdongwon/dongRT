/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:45:51 by cwon              #+#    #+#             */
/*   Updated: 2025/10/28 13:33:36 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>

#include "libft.h"

static bool	is_object(const char *id)
{
	const char	*obj_id[] = {"cy", "pl", "sp", NULL};
	size_t		i;

	i = 0;
	while (obj_id[i])
	{
		if (ft_strcmp(id, obj_id[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

static char	*get_identifier(t_list *list)
{
	return ((char *)list->content);
}

void	parse_list(t_parser *parser)
{
	char	*id;

	id = get_identifier(parser->list);
	if (ft_strcmp(id, "A") == 0)
		parse_ambient(parser);
	else if (ft_strcmp(id, "C") == 0)
		parse_camera(parser);
	else if (ft_strcmp(id, "L") == 0)
		parse_light(parser);
	else if (is_object(id))
		parse_object(parser);
	else
		parser_error("parse_list", "unknown identifier", parser);
}
