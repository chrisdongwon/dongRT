/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:30:53 by cwon              #+#    #+#             */
/*   Updated: 2026/03/01 14:17:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOTLIGHT_BONUS_H
# define SPOTLIGHT_BONUS_H

# include "color_bonus.h"
# include "vector_bonus.h"

typedef struct s_hit		t_hit;
typedef struct s_parser		t_parser;
typedef struct s_spotlight	t_spotlight;

struct s_spotlight
{
	double		brightness;
	t_color		color;
	t_vector	dir;
	t_vector	pos;
};

// spotlight_bonus.c
bool	in_spotlight(const t_hit *h, const t_spotlight *s);
void	append_spotlight(t_parser *p, t_spotlight *s);

#endif
