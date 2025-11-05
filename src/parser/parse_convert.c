/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:01 by cwon              #+#    #+#             */
/*   Updated: 2025/11/05 15:51:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "color.h"
#include "libft.h"
#include "mini_rt.h"

void	get_ratio(t_parser *p, size_t index)
{
	char	*str;

	str = (char *)ft_lstget(p->list, index);
	if (!ft_isfloat(str))
		parser_error(p, "Ratio must be numeric");
	p->ratio = ft_atof(str);
	if (p->ratio < 0.0 || p->ratio > 1.0)
		parser_error(p, "Ratio out of range [0, 1]");
	return (p->ratio);
}

void	get_color(t_parser *p, size_t index)
{
	char	**arr;
	char	*str;
	int		rgb[3];

	str = (char *)ft_lstget(p->list, index);
	check_terminal_comma(p, str);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	check_rgb(p, arr);
	p->color.r = ft_atof(arr[0]) / 255.0;
	p->color.g = ft_atof(arr[1]) / 255.0;
	p->color.b = ft_atof(arr[2]) / 255.0;
	ft_split_free(arr);
}
