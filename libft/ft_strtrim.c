/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:29:19 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 21:53:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	end--;
	while (s1[start] && ft_ismember(s1[start], set))
		start++;
	while (end > start && ft_ismember(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
