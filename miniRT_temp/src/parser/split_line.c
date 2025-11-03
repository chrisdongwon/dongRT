/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:28:26 by cwon              #+#    #+#             */
/*   Updated: 2025/10/27 15:33:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

static bool	add_token_to_list(t_list **head, char *token)
{
	t_list	*node;

	node = ft_lstnew(token);
	if (!node)
	{
		free(token);
		return (false);
	}
	ft_lstadd_back(head, node);
	return (true);
}

static char	*extract_token(const char *line, size_t *i)
{
	size_t	start;

	start = *i;
	while (line[*i] && !ft_isspace((unsigned char)line[*i]))
		(*i)++;
	return (ft_substr(line, start, *i - start));
}

static size_t	skip_whitespace(const char *str, size_t i)
{
	while (str[i] && ft_isspace((unsigned char)str[i]))
		i++;
	return (i);
}

static void	split_line_error(t_parser *parser)
{
	ft_lstclear(&parser->list, free);
	free(parser->line);
	close(parser->fd);
	get_next_line(-1, NULL);
	mini_rt_error("split_line", strerror(errno), parser->scene);
}

void	split_line(t_parser *parser)
{
	char	*token;
	size_t	i;

	i = 0;
	while (parser->line[i] != '\0')
	{
		i = skip_whitespace(parser->line, i);
		if (parser->line[i] == '\0')
			break ;
		token = extract_token(parser->line, &i);
		if (!token || !add_token_to_list(&parser->list, token))
			split_line_error(parser);
	}
	if (parser->list == NULL)
		split_line_error(parser);
}
