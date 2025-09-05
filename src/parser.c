/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:43:41 by cwon              #+#    #+#             */
/*   Updated: 2025/09/05 13:30:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <fcntl.h>

#include "libft.h"

static int	get_tokens(char *tokens[7], char *line)
{
	char	*tok;
	int		count;

	count = 0;
	tok = ft_strtok(line, " \t");
	while (tok)
	{
		if (count >= 7)
			fatal("Too many arguments on line");
		tokens[count++] = tok;
		tok = ft_strtok(NULL, " \t");
	}
	return (count);
}

static void	parse_line(char *line, t_parser *parser)
{
	char	*tok;
	char	*tokens[7];
	int		count;

	count = get_tokens(tokens, line);
	if (count == 0)
		return ;
	if (ft_strcmp(tokens[0], "A") == 0)
		parse_ambient(tokens, count, parser);
	else if (ft_strcmp(tokens[0], "C") == 0)
		parse_camera(tokens, count, parser);
	else if (ft_strcmp(tokens[0], "L") == 0)
		parse_light(tokens, count, parser);
	else if (ft_strcmp(tokens[0], "sp") == 0)
		parse_sphere(tokens, count);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		parse_plane(tokens, count);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		parse_cylinder(tokens, count);
	else
		fatal("Unknown identifier");
}

static void	parse_file(int fd, t_parser *parser)
{
	char	*line;
	char	*trimmed;

	while (get_next_line(fd, &line))
	{
		trimmed = trim(line);
		if (*trimmed != '\0')
			parse_line(trimmed, parser);
		free(line);
	}
}

void	parse(const char *filename)
{
	int			fd;
	t_parser	parser;

	if (!has_rt_extension(filename))
		fatal("File must have .rt extension");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		fatal("Could not open file");
	init_parser(&parser);
	parse_file(fd, &parser);
	close(fd);
	validate_parser(&parser);
}
