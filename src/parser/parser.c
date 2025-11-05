/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:23:37 by cwon              #+#    #+#             */
/*   Updated: 2025/11/05 15:10:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "dispatcher.h"
#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

void	flush_parser(t_parser *p)
{
	if (p->fd != 0)
		close(p->fd);
	get_next_line(-1, NULL);
	reset_parser(p);
}

void	init_parser(t_parser *p, const char *filename, t_scene *scene)
{
	static t_dispatcher	entries[] = {\
{"A", parse_ambient}, \
{"C", parse_camera}, \
{"L", parse_light}, \
{"sp", parse_sphere}, \
{"pl", parse_plane}, \
{"cy", parse_cylinder}, \
{NULL, NULL}};

	ft_memset(p, 0, sizeof(t_parser));
	p->fd = open(filename, O_RDONLY);
	if (p->fd < 0)
		mini_rt_error(scene);
	p->scene = scene;
	p->subparser = entries;
}

void	parser_error(t_parser *p, const char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd("miniRT: ", STDERR_FILENO);
	ft_putstr_fd(p->id, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	flush_parser(p);
	flush_scene(p->scene);
	exit(EXIT_FAILURE);
}

void	reset_parser(t_parser *p)
{
	free(p->line);
	ft_lstclear(&p->list, free);
}
