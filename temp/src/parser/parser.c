/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:34:34 by cwon              #+#    #+#             */
/*   Updated: 2025/09/06 22:14:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

void	init_parser(t_parser *parser)
{
	ft_memset(parser, 0, sizeof(t_parser));
}

void	validate_parser(t_parser *parser)
{
	if (!parser->has_ambient)
		fatal("No ambient light defined");
	if (!parser->has_camera)
		fatal("No camera defined");
	if (!parser->has_light)
		fatal("No light defined");
}
