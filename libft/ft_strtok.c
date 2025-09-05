/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:35:19 by cwon              #+#    #+#             */
/*   Updated: 2025/09/05 12:38:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	char		*start;
	static char	*next = NULL;

	if (str)
		next = str;
	if (!next)
		return (NULL);
	while (*next && ft_strchr(delim, *next))
		next++;
	if (!*next)
		return (NULL);
	start = next;
	while (*next && !ft_strchr(delim, *next))
		next++;
	if (*next)
	{
		*next = '\0';
		next++;
	}
	return (start);
}
