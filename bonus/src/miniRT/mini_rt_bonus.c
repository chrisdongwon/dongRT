/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:42:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

#include <stdio.h>
#include <stdlib.h>

#include "scene_bonus.h"
#include "parser_bonus.h"
#include "renderer_bonus.h"

void	mini_rt_error(t_scene *scene)
{
	perror("miniRT");
	flush_scene(scene);
	exit(EXIT_FAILURE);
}

void	mini_rt(int argc, char **argv)
{
	t_scene	scene;

	validate_arg(argc, argv);
	init_scene(&scene);
	parse(argv[1], &scene);
	render(&scene);
	flush_scene(&scene);
}
