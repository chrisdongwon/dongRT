/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:16:44 by cwon              #+#    #+#             */
/*   Updated: 2025/10/27 13:17:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_split_free(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
