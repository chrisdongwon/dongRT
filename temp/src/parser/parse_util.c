/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:22:58 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:09:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"
#include "rgb.h"
#include "vector.h"

static size_t	split_str(char *str, char **out)
{
	char	*token;
	size_t	count;

	count = 0;
	token = ft_strtok(str, ",");
	while (token && count < 3)
	{
		out[count++] = token;
		token = ft_strtok(NULL, ",");
	}
	return (count);
}

bool	parse_double(const char *str, double *out)
{
	const char	*p;
	double		value;

	p = str;
	while (*p)
	{
		if (!(ft_isdigit((unsigned char)*p) || \
*p == '.' || *p == '-' || *p == '+'))
			return (false);
		p++;
	}
	value = ft_atof(str);
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

bool	parse_rgb_str(char *str, t_rgb *color)
{
	char	*parts[3];
	int		count;

	if (!str || !color || ft_countchar(str, ',') != 2)
		return (false);
	count = split_str(str, parts);
	return (count == 3 && parse_int(parts[0], &color->r) && \
parse_int(parts[1], &color->g) && parse_int(parts[2], &color->b) && \
is_valid_rgb(color));
}

bool	parse_vector_str(char *str, t_vector *vec, bool is_normalized)
{
	char	*parts[3];
	int		count;

	if (!str || !vec || ft_countchar(str, ',') != 2)
		return (false);
	count = split_str(str, parts);
	if (count != 3 || !parse_double(parts[0], &vec->x) || \
!parse_double(parts[1], &vec->y) || !parse_double(parts[2], &vec->z))
		return (false);
	if (is_normalized)
		return (ft_isbetween(vec->x, -1.0, 1.0) && \
ft_isbetween(vec->y, -1.0, 1.0) && ft_isbetween(vec->z, -1.0, 1.0));
	return (true);
}
