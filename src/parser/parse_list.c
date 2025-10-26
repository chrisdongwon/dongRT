/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:45:51 by cwon              #+#    #+#             */
/*   Updated: 2025/10/26 15:56:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>

#include "libft.h"

static bool	is_object(const char *id)
{
	char	*objects[3];
	size_t	i;

	objects[0] = "sp";
	objects[1] = "pl";
	objects[2] = "cy";
	i = 0;
	while (i < 3)
	{
		if (ft_strcmp(id, objects[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

static char	*get_identifier(t_list *list)
{
	return ((char *)list->content);
}

void	parse_list(t_list *list, t_scene *scene)
{
	char	*id;

	id = get_identifier(list);
	if (ft_strcmp(id, "A") == 0)
		parse_ambient(list, scene);
	else if (ft_strcmp(id, "C") == 0)
		parse_camera(list, scene);
	else if (ft_strcmp(id, "L") == 0)
		parse_light(list, scene);
	else if (is_object(id))
		parse_object(list, scene);
	else
		parser_error("parse_list", "unknown identifier", scene);
}
