/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:14 by cwon              #+#    #+#             */
/*   Updated: 2026/03/08 13:05:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

typedef struct s_minilibx	t_minilibx;
typedef struct s_renderer	t_renderer;
typedef struct s_scene		t_scene;

struct s_renderer
{
	t_minilibx	*minilibx;
	t_scene		*scene;
	int			width;
	int			height;
};

// render_util.c
// int	redraw(void *param);
// int	resize(int width, int height, void *param);
// void	render_scene_image(t_renderer *r);

// render.c
void		render(t_scene *s);

// renderer.c
t_renderer	init_renderer(t_scene *s, t_minilibx *m);
void		flush_renderer(t_renderer *r);

#endif
