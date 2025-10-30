/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:38 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 15:37:36 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>

#include "libft.h"
#include "scene.h"

static void	validate_light_argc(t_parser *parser)
{
	if (parser->scene->light != NULL)
		parser_error("parse_light", "multiple declarations", parser);
	if (ft_lstsize(parser->list) != 4)
		parser_error("parse_light", "invalid format", parser);
}

void	parse_light(t_parser *parser)
{
	t_list	*node;

	validate_light_argc(parser);
	node = parser->list->next;
	
}
