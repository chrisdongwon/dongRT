/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:41:23 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 13:43:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "color.h"

typedef struct s_camera	t_camera;
typedef struct s_list	t_list;
typedef struct s_scene	t_scene;

struct					s_camera;
struct					s_list;

struct s_scene
{
	t_camera	*cam;
	t_color		*ambient;
	t_color		background;
	t_list		*lights;
	t_list		*objects;
};

// scene.c
void	init_scene(t_scene *scene);
void	flush_scene(t_scene *scene);

#endif
