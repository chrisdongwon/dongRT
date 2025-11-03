/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:09:11 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 07:30:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

static void	rgb_error(char **arr, t_parser *p, char *msg)
{
	ft_split_free(arr);
	parser_error("validate_rgb", msg, p);
}

void	validate_rgb(char **arr, t_parser *p)
{
	int		rgb[3];
	size_t	i;

	if (ft_split_size(arr) != 3)
		rgb_error(arr, p, "invalid RGB format");
	i = 0;
	while (i < 3)
	{
		if (!ft_isinteger(arr[i]))
			rgb_error(arr, p, "RGB values must be integers");
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			rgb_error(arr, p, "RGB value out of range [0, 255]");
		i++;
	}
}
