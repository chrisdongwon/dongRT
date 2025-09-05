/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:00:05 by cwon              #+#    #+#             */
/*   Updated: 2025/09/05 12:26:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

bool	has_rt_extension(const char *filename)
{
	size_t  len;

	len = ft_strlen(filename);
	return (len > 3 && ft_strcmp(filename + len - 3, ".rt") == 0);
}

char	*trim(char *str)
{
	char	*end;

	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '\0')
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

void	fatal(const char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	init_parser(t_parser *parser)
{
	parser->ambient = false;
	parser->camera = false;
	parser->light = false;
}

void	validate_parser(t_parser *parser)
{
	if (!parser->ambient)
		fatal("No ambient light defined");
	if (!parser->camera)
		fatal("No camera defined");
	if (!parser->light)
		fatal("No light defined");
}
