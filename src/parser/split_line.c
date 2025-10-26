/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:28:26 by cwon              #+#    #+#             */
/*   Updated: 2025/10/26 14:20:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"
#include "miniRT.h"
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
	char	*token;
	size_t	start;

	start = *i;
	while (line[*i] && !ft_isspace((unsigned char)line[*i]))
		(*i)++;
	token = ft_substr(line, start, *i - start);
	return (token);
}

static size_t	skip_whitespace(const char *str, size_t i)
{
	while (str[i] && ft_isspace((unsigned char)str[i]))
		i++;
	return (i);
}

static void	split_line_error(char *line, t_list *head, t_scene *scene)
{
	ft_lstclear(&head, free);
	free(line);
	error_exit("split_line", strerror(errno), scene);
}

t_list	*split_line(char *line, t_scene *scene)
{
	char	*token;
	size_t	i;
	t_list	*head;

	head = NULL;
	i = 0;
	while (line[i] != '\0')
	{
		i = skip_whitespace(line, i);
		if (line[i] == '\0')
			break ;
		token = extract_token(line, &i);
		if (!token || !add_token_to_list(&head, token))
			split_line_error(line, head, scene);
	}
	if (head == NULL)
		split_line_error(line, head, scene);
	return (head);
}
