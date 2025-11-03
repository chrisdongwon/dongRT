/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:07:37 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 09:15:51 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

static void	vector_error(char **arr, t_parser *p, char *msg)
{
	ft_split_free(arr);
	parser_error("validate_vector", msg, p);
}

void	validate_vector(char **arr, t_parser *p, double xyz[3])
{
	size_t	i;

	if (ft_split_size(arr) != 3)
		vector_error(arr, p, "invalid vector format");
	i = 0;
	while (i < 3)
	{
		if (!ft_isfloat(arr[i]))
			vector_error(arr, p, "vector values must be numeric");
		xyz[i] = ft_atof(arr[i]);
		i++;
	}
}
