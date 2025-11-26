/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:21:31 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:43:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

#include <stdlib.h>

#include "dispatcher_bonus.h"
#include "libft.h"
#include "mini_rt_bonus.h"

static char	*trim_whitespace(char *line, t_parser *p)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, "\t\n\v\f\r ");
	if (trimmed == NULL)
	{
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	free(line);
	return (trimmed);
}

static void	parse_element(t_parser *p)
{
	p->list = ft_split_list(p->line, "\t\n\v\f\r ");
	if (p->list == NULL)
	{
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	dispatch_subparser(p);
}

void	parse(const char *filename, t_scene *scene)
{
	t_parser	p;

	init_parser(&p, filename, scene);
	while (get_next_line(p.fd, &p.line))
	{
		p.line = trim_whitespace(p.line, &p);
		if (*p.line != '\0')
			parse_element(&p);
		reset_parser(&p);
	}
	flush_parser(&p);
}
