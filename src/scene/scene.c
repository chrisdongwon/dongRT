/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:09 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 12:52:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <stdlib.h>

#include "libft.h"
#include "object.h"

void	init_scene(t_scene *const scene)
{
	ft_memset(scene, 0, sizeof(*scene));
}

void	flush_scene(t_scene *const scene)
{
	free(scene->ambient);
	free(scene->camera);
	free(scene->light);
	ft_lstclear(&scene->objects, free_object);
}
