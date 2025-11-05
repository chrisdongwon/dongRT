/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:56:29 by cwon              #+#    #+#             */
/*   Updated: 2025/11/05 15:52:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

void	check_multiple_declarations(t_parser *p, void *ptr)
{
	if (ptr != NULL)
		parser_error(p, "Multiple declaration detected");
}

void	check_rgb(t_parser *p, char **arr)
{
	int		temp;
	size_t	i;

	i = 0;
	while(arr[i])
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

void	check_terminal_comma(t_parser *p, const char *str)
{
	if (str[ft_strlen(str) - 1] == ',')
		parser_error(p, "Invalid format");
}

void	check_token_count(t_parser *p, size_t expected)
{
	if (ft_lstsize(p->list) != expected)
		parser_error(p, "Invalid argument count");
}
