/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:45:51 by cwon              #+#    #+#             */
/*   Updated: 2025/10/31 12:49:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

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
	else if (ft_strcmp(id, "sp") == 0)
		parse_sphere(parser);
	else if (ft_strcmp(id, "pl") == 0)
		parse_plane(parser);
	else if (ft_strcmp(id, "cy") == 0)
		parse_cylinder(parser);
	else
		parser_error("parse_list", "unknown identifier", parser);
}
