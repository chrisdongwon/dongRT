/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:30:13 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 21:23:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "parser.h"
#include "scene.h"

void	error_exit(const char *context, const char *msg, t_scene *scene)
{
	ft_putstr_fd("miniRT: ", STDERR_FILENO);
	if (context != NULL)
	{
		ft_putstr_fd(context, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd((char *)msg, STDERR_FILENO);
	if (scene != NULL)
		flush_scene(scene);
	exit(EXIT_FAILURE);
}

void	mini_rt(const int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parse(argc, argv, &scene);
	// process
	flush_scene(&scene);
}
