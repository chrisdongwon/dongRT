/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:22:48 by cwon              #+#    #+#             */
/*   Updated: 2025/10/26 22:44:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"
#include "scene.h"

// TO DO:
// replace ft_lstget_nth
// check if 1st argument is a valid float before conversion
// make sure parse_color can handle cases where last number in the list (rgB) is
// terminated correctly
void	parse_ambient(t_list *list, t_scene *scene)
{
	ft_printf("ambient identifier detected\n");

	if (scene->ambient_light != NULL)
		parser_error("parse_ambient", "multiple declaration", scene);
	if (ft_lstsize(list) != 3)
		parser_error("parse_ambient", "invalid ambient format", scene);
	
	// double	ratio = ft_atof(ft_lstget(tokens, 1)->content);
	// if (ratio < 0.0 || ratio > 1.0)
	// 	error_exit("invalid ambient ratio", ft_lstget(tokens, 1)->content);
	
	// scene->ambient_light = parse_color(ft_lstget(tokens, 2)->content);
	// scene->ambient_light.r *= ratio;
	// scene->ambient_light.g *= ratio;
	// scene->ambient_light.b *= ratio;
}
