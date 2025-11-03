/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:08:13 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 15:49:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

#include "scene.h"

void	mini_rt(const int argc, char **argv)
{
	t_scene	scene;

	validate_arg(argc, argv);
	parser(argv[1], &scene);
	flush_scene(&scene);
}
