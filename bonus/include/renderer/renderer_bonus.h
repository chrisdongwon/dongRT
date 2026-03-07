/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:46:14 by cwon              #+#    #+#             */
/*   Updated: 2026/03/07 14:55:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_BONUS_H
# define RENDERER_BONUS_H

# include "color_bonus.h"

# define KA 0.05
# define KD 1.0
# define KS 0.35
# define SHININESS 100

typedef struct s_camera		t_camera;
typedef struct s_hit		t_hit;
typedef struct s_light		t_light;
typedef struct s_minilibx	t_minilibx;
typedef struct s_renderer	t_renderer;
typedef struct s_scene		t_scene;
typedef struct s_spotlight	t_spotlight;

struct s_renderer
{
	t_minilibx	*minilibx;
	t_scene		*scene;
};

// bump_map_bonus.c
void		bump_map(t_hit *hit);

// checkerboard_bonus.c
t_color		checkerboard(const t_hit *hit);

// phong_bonus.c
t_color		phong_diffuse(const t_hit *h, const t_light *l, t_color color);
t_color		phong_shade(const t_hit *h, const t_scene *s, t_color color);
t_color		phong_specular(const t_hit *h, const t_light *l, const t_camera *c);

// phong_util_bonus.c
t_color		contribute_light(const t_hit *h, const t_scene *s, t_color color);
t_color		contribute_spot(const t_hit *h, const t_spotlight *s, \
const t_camera *c, t_color obj_color);

// render_bonus.c
void		render(t_scene *s);

// renderer_bonus.c
t_renderer	init_renderer(t_scene *s, t_minilibx *m);
void		flush_renderer(t_renderer *r);

#endif
