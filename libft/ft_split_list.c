/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:48:05 by cwon              #+#    #+#             */
/*   Updated: 2025/11/04 13:31:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static bool	add_token_to_list(t_list **head, const char *token)
{
	char	*copy;
	t_list	*new_node;

	copy = ft_strdup(token);
	if (!copy)
		return (false);
	new_node = ft_lstnew(copy);
	if (!new_node)
	{
		free(copy);
		return (false);
	}
	ft_lstadd_back(head, new_node);
	return (true);
}

t_list	*ft_split_list(const char *s, const char *delim)
{
	char	*dup;
	char	*token;
	t_list	*head;

	if (!s)
		return (NULL);
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	head = NULL;
	token = ft_strtok(dup, delim);
	while (token)
	{
		if (!add_token_to_list(&head, token))
		{
			ft_lstclear(&head, free);
			free(dup);
			return (NULL);
		}
		token = ft_strtok(NULL, delim);
	}
	free(dup);
	return (head);
}
