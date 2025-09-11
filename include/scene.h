/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:14:16 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 08:54:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"

# include "ambient.h"
# include "camera.h"
# include "light.h"

# include "sphere.h"
# include "plane.h"
# include "cylinder.h"

typedef struct s_scene	t_scene;

struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;

	t_list		*spheres;
	t_list		*planes;
	t_list		*cylinders;
};

void	flush_scene(t_scene *scene);
void	init_scene(t_scene *scene);
void	print_scene(t_scene *scene);

#endif
