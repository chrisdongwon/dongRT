/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:26:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 12:08:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

void	check_rgb(t_parser *p, char **arr)
{
	int		temp;
	size_t	i;

	i = 0;
	while (arr[i])
	{
		if (i == 3)
		{
			ft_split_free(arr);
			parser_error(p, "Invalid RGB format");
		}
		if (!ft_isinteger(arr[i]))
		{
			ft_split_free(arr);
			parser_error(p, "RGB values must be integers");
		}
		temp = ft_atoi(arr[i]);
		if (temp < 0 || temp > 255)
		{
			ft_split_free(arr);
			parser_error(p, "RGB value out of range [0, 255]");
		}
		i++;
	}
}

void	check_vector(t_parser *p, char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		if (i == 3)
		{
			ft_split_free(arr);
			parser_error(p, "Invalid vector format");
		}
		if (!ft_isfloat(arr[i]))
		{
			ft_split_free(arr);
			parser_error(p, "Vector values must be numeric");
		}
		i++;
	}
}
