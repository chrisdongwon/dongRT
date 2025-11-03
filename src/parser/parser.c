/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:23:37 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 22:32:39 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "mini_rt.h"
#include "scene.h"

void	flush_parser(t_parser *p)
{
	if (p->fd != 0)
		close(p->fd);
	free(p->line);
	get_next_line(-1, NULL);
	flush_scene(p->scene);
}

void	init_parser(t_parser *p, const char *filename, t_scene *scene)
{
	p->fd = open(filename, O_RDONLY);
	if (p->fd < 0)
		mini_rt_error(scene);
	p->line = NULL;
	p->scene = scene;
}

void	parser(const char *filename, t_scene *scene)
{
	t_parser	p;
	
	init_parser(&p, filename, scene);
	// STUB
	flush_parser(&p);
}
