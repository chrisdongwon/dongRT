/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:57:25 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 14:53:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <stdlib.h>

#include "libft.h"
#include "object.h"

void	init_scene(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(t_scene));
}

void	flush_scene(t_scene *scene)
{
	ft_lstclear(&scene->lights, free);
	ft_lstclear(&scene->objects, flush_object);
}
