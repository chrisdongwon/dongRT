/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:42:30 by cwon              #+#    #+#             */
/*   Updated: 2025/10/28 15:21:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

static int	get_scene_fd(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		mini_rt_error(path, strerror(errno), 0);
	return (fd);
}

void	init_parser(t_parser *parser, t_scene *scene, const char *path)
{
	parser->line = NULL;
	parser->fd = get_scene_fd(path);
	parser->list = NULL;
	parser->scene = scene;
}

void	flush_parser(t_parser *parser)
{
	free(parser->line);
	if (parser->fd != 0)
		close(parser->fd);
	ft_lstclear(&parser->list, free);
	get_next_line(-1, NULL);
}

void	parse(const int argc, char **argv, t_scene *scene)
{
	t_parser	parser;

	validate_arg(argc, argv);
	init_parser(&parser, scene, argv[1]);
	parse_lines(&parser);
	close(parser.fd);
	// validate_scene(scene);
}

void	parser_error(const char *context, const char *msg, t_parser *parser)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	flush_parser(parser);
	mini_rt_error(context, msg, parser->scene);
}
