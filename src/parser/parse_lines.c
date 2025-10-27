/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:09:09 by cwon              #+#    #+#             */
/*   Updated: 2025/10/27 15:37:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

static char	*trim_line(t_parser *parser)
{
	char	*trimmed;

	trimmed = ft_strtrim(parser->line, "\t\n\v\f\r ");
	free(parser->line);
	if (trimmed == NULL)
	{
		close(parser->fd);
		get_next_line(-1, NULL);
		mini_rt_error("ft_strtrim", strerror(errno), parser->scene);
	}
	return (trimmed);
}

static void	reset_list(t_parser *parser)
{
	ft_lstclear(&parser->list, free);
	parser->list = NULL;
}

void	parse_lines(t_parser *parser)
{
	while (get_next_line(parser->fd, &parser->line))
	{
		parser->line = trim_line(parser);
		if (*(parser->line) != '\0')
		{
			split_line(parser);
			parse_list(parser);
			reset_list(parser);
		}
		free(parser->line);
	}
}
