/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:01 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 13:39:51 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "color.h"
#include "libft.h"
#include "mini_rt.h"
#include "vector.h"

double	get_float(t_parser *p, size_t index)
{
	const char	*str;
	double		value;

	str = (const char *)ft_lstget(p->list, index);
	if (!ft_isfloat(str))
		parser_error(p, "Value must be numeric");
	value = ft_atof(str);
	if (value <= 0.0)
		parser_error(p, "Value must be positive");
	return (value);
}

double	get_fov(t_parser *p, size_t index)
{
	const char	*str;
	double		fov;

	str = (char *)ft_lstget(p->list, index);
	if (!ft_isfloat(str))
		parser_error(p, "FOV must be numeric");
	fov = ft_atof(str);
	if (fov < 0.0 || fov > 180.0)
		parser_error(p, "FOV out of range [0, 180]");
	return (fov);
}

double	get_ratio(t_parser *p, size_t index)
{
	const char	*str;
	double		ratio;

	str = (char *)ft_lstget(p->list, index);
	if (!ft_isfloat(str))
		parser_error(p, "Ratio must be numeric");
	ratio = ft_atof(str);
	if (ratio < 0.0 || ratio > 1.0)
		parser_error(p, "Ratio out of range [0, 1]");
	return (ratio);
}

t_color	get_color(t_parser *p, size_t index)
{
	char		**arr;
	const char	*str;
	t_color		color;

	str = (char *)ft_lstget(p->list, index);
	check_commas(p, str);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	check_rgb(p, arr);
	color.r = ft_atof(arr[0]) / 255.0;
	color.g = ft_atof(arr[1]) / 255.0;
	color.b = ft_atof(arr[2]) / 255.0;
	ft_split_free(arr);
	return (color);
}

t_vector	get_vector(t_parser *p, size_t index, bool normalized)
{
	char		**arr;
	const char	*str;
	t_vector	v;

	str = (char *)ft_lstget(p->list, index);
	check_commas(p, str);
	arr = ft_split(str, ',');
	if (arr == NULL)
	{
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	check_vector(p, arr);
	v.x = ft_atof(arr[0]);
	v.y = ft_atof(arr[1]);
	v.z = ft_atof(arr[2]);
	ft_split_free(arr);
	if (normalized && !is_normalized(v))
		parser_error(p, "Directional vector must be normalized");
	return (v);
}
