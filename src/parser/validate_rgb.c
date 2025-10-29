/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:09:11 by cwon              #+#    #+#             */
/*   Updated: 2025/10/29 15:43:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

static void	validate_token_count(char **arr, t_parser *p)
{
	if (ft_split_size(arr) != 3)
	{
		ft_split_free(arr);
		parser_error("validate_rgb", "invalid RGB format", p);
	}
}

void	validate_rgb(char **arr, t_parser *p)
{
	int		rgb[3];
	size_t	i;

	validate_token_count(arr, p);
	i = 0;
	while (i < 3)
	{
		if (!ft_isinteger(arr[i]))
		{
			ft_split_free(arr);
			parser_error("validate_rgb", "RGB values must be integers", p);
		}
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_split_free(arr);
			parser_error("validate_rgb", "RGB value out of range [0, 255]", p);
		}
		i++;
	}
}
