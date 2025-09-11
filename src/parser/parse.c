/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:43:39 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 12:18:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "scene.h"

static t_parser_status	parse_token(char *line, t_scene *scene, \
t_parser *parser)
{
	char	*tokens[MAX_TOKENS];
	int		count;

	count = get_tokens(tokens, line);
	if (count < 0)
		return (PARSER_ERROR);
	if (count == 0)
		return (PARSER_EMPTY);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (parse_ambient(tokens, count, scene, parser));
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (parse_camera(tokens, count, scene, parser));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (parse_light(tokens, count, scene, parser));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (parse_sphere(tokens, count, scene));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (parse_plane(tokens, count, scene));
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (parse_cylinder(tokens, count, scene));
	return (PARSER_ERROR);
}

static void	parse_line(int fd, t_scene *scene, t_parser *parser)
{
	char	*line;
	char	*trimmed;

	while (get_next_line(fd, &line) && line != NULL)
	{
		trimmed = trim_whitespace(line);
		if (*trimmed != '\0')
		{
			if (parse_token(trimmed, scene, parser) == PARSER_ERROR)
			{
				free(line);
				close(fd);
				get_next_line(-1, NULL);
				flush_scene(scene);
				fatal("Parser error in scene file");
			}
		}
		free(line);
	}
}

static void	parse_file(const char *filename, t_scene *scene)
{
	int			fd;
	t_parser	parser;

	init_parser(&parser);
	if (!has_rt_extension(filename))
		fatal("File must have .rt extension");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		fatal("Could not open file");
	parse_line(fd, scene, &parser);
	close(fd);
	validate_parser(&parser);
}

void	parse(const int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		usage_message(argv);
	init_scene(&scene);
	parse_file(argv[1], &scene);
	print_scene(&scene);
	flush_scene(&scene);
}
