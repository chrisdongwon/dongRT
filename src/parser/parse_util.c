/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:22:58 by cwon              #+#    #+#             */
/*   Updated: 2025/09/10 16:54:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"
#include "rgb.h"
#include "vector.h"

static bool	free_str_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (false);
}

bool	parse_float(const char *str, float *out)
{
	const char	*p;
	float		value;

	p = str;
	while (*p)
	{
		if (!(ft_isdigit((unsigned char)*p) || \
*p == '.' || *p == '-' || *p == '+'))
			return (false);
		p++;
	}
	value = (float)ft_atof(str);
	if (value == 0.0f && str[0] != '0')
		return (false);
	*out = value;
	return (true);
}

bool	parse_int(const char *s, int *out)
{
	if (!ft_isinteger(s))
		return (false);
	*out = ft_atoi(s);
	return (true);
}

bool	parse_rgb_str(const char *str, t_rgb *color)
{
	char	**arr;
	size_t	i;

	arr = ft_split(str, ',');
	if (arr == NULL)
		fatal("ft_split failed");
	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
		return (free_str_array(arr));
	if (ft_isinteger(arr[0]) && ft_isinteger(arr[1]) && ft_isinteger(arr[2]))
	{
		color->r = ft_atoi(arr[0]);
		color->g = ft_atoi(arr[1]);
		color->b = ft_atoi(arr[2]);
	}
	else
		return (free_str_array(arr));
	free_str_array(arr);
	return (is_valid_rgb(color));
}

bool	parse_vector_str(const char *str, t_vector *vec, bool is_normalized)
{
	char	**arr;
	size_t	i;

	arr = ft_split(str, ',');
	if (arr == NULL)
		fatal("ft_split failed");
	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
		return (free_str_array(arr));
	if (!parse_float(arr[0], &vec->x) || !parse_float(arr[1], &vec->y) || \
!parse_float(arr[2], &vec->z))
		return (free_str_array(arr));
	free_str_array(arr);
	if (is_normalized)
		return (is_normed(vec));
	return (true);
}
