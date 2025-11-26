/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:21:09 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:45:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_bonus.h"

#include <stdlib.h>

#include "libft.h"
#include "object_bonus.h"

void	init_scene(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(*scene));
}

void	flush_scene(t_scene *scene)
{
	free(scene->ambient);
	free(scene->camera);
	free(scene->light);
	ft_lstclear(&scene->objects, free_object);
}
