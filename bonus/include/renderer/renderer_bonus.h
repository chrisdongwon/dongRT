/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:14 by cwon              #+#    #+#             */
/*   Updated: 2026/02/22 14:37:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_BONUS_H
# define RENDERER_BONUS_H

# include "color_bonus.h"

typedef struct s_hit		t_hit;
typedef struct s_minilibx	t_minilibx;
typedef struct s_renderer	t_renderer;
typedef struct s_scene		t_scene;

struct s_renderer
{
	t_minilibx	*minilibx;
	t_scene		*scene;
};

// checkerboard_bonus.c
t_color		checkerboard(const t_hit *hit);

// render_bonus.c
void		render(t_scene *s);

// renderer_bonus.c
t_renderer	init_renderer(t_scene *s, t_minilibx *m);
void		flush_renderer(t_renderer *r);

#endif
