/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:07:31 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 13:33:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# define ESC_KEY 65307
# define X_BUTTON 17

# include <stdbool.h>

typedef struct s_minilibx	t_minilibx;
typedef struct s_renderer	t_renderer;
typedef struct s_scene		t_scene;

struct s_minilibx
{
	char	*addr;
	int		bpp;
	int		endian;
	int		ll;
	void	*img;
	void	*mlx;
	void	*win;
};

// minilibx.c
bool	init_minilibx(t_minilibx *const m);
int		close_window(t_renderer *const r);
int		create_trgb(int t, int r, int g, int b);
int		handle_key(int keycode, t_renderer *const r);
void	put_pixel(t_minilibx *const m, int x, int y, int color);

#endif
