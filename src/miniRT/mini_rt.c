/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 13:35:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

#include <stdio.h>
#include <stdlib.h>

#include "scene.h"
#include "parser.h"
#include "renderer.h"

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
