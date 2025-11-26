/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:14 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:36:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_BONUS_H
# define RENDERER_BONUS_H

typedef struct s_minilibx	t_minilibx;
typedef struct s_renderer	t_renderer;
typedef struct s_scene		t_scene;

struct s_renderer
{
	t_minilibx	*minilibx;
	t_scene		*scene;
};

// render.c
void		render(t_scene *s);

// renderer.c
t_renderer	init_renderer(t_scene *s, t_minilibx *m);
void		flush_renderer(t_renderer *r);

#endif
