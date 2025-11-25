/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:49 by cwon              #+#    #+#             */
/*   Updated: 2025/11/20 13:42:59 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include "hit.h"

typedef struct s_dispatcher	t_dispatcher;
typedef struct s_parser		t_parser;
typedef struct s_ray		t_ray;
typedef struct s_renderer	t_renderer;
typedef t_hit				(*t_hit_fn)(const t_ray *, const t_object *);
typedef void				(*t_parser_fn)(t_parser *);

struct s_dispatcher
{
	const char	*id;
	t_parser_fn	parse_fn;
	t_hit_fn	hit_fn;
};

// dispatcher.c
t_hit_fn	get_hit_fn(t_parser *p);
void		dispatch_subparser(t_parser *p);

#endif
