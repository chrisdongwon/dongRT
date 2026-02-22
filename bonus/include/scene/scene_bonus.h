/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:10:19 by cwon              #+#    #+#             */
/*   Updated: 2026/02/22 16:39:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H

typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_list		t_list;
typedef struct s_scene		t_scene;

struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_list		*objects;
	t_list		*spotlights;
};

// scene_bonus.c
void	init_scene(t_scene *scene);
void	flush_scene(t_scene *scene);

#endif
