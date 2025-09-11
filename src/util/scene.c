/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:19:39 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 08:55:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"

void	flush_scene(t_scene *scene)
{
	ft_lstclear(&scene->spheres, free);
	ft_lstclear(&scene->planes, free);
	ft_lstclear(&scene->cylinders, free);
}

void	init_scene(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(t_scene));
}

void	print_scene(t_scene *scene)
{
	printf("Ambient: ratio=%.2f, color=", scene->ambient.ratio);
	print_rgb(&scene->ambient.color);
	printf("\n");
	printf("Camera: origin=");
	print_vector(&scene->camera.pos);
	printf(", orientation=");
	print_vector(&scene->camera.dir);
	printf(", fov=%d\n", scene->camera.fov);
	printf("Light: origin=");
	print_vector(&scene->light.pos);
	printf(", brightness=%.2f, color=", scene->light.brightness);
	print_rgb(&scene->light.color);
	printf("\n");
	printf("Objects:\n");
	ft_lstiter(scene->spheres, print_sphere);
	ft_lstiter(scene->planes, print_plane);
	ft_lstiter(scene->cylinders, print_cylinder);
}
