/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:56:29 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 13:34:18 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>

#include "libft.h"
#include "mini_rt.h"

void	*parser_malloc(t_parser *p, const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		flush_parser(p);
		mini_rt_error(p->scene);
	}
	return (ptr);
}

void	check_multiple_declarations(t_parser *p, void *ptr)
{
	if (ptr != NULL)
		parser_error(p, "Multiple declaration detected");
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
