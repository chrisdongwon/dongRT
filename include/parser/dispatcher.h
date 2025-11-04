/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:49 by cwon              #+#    #+#             */
/*   Updated: 2025/11/04 14:44:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

typedef struct s_dispatcher	t_dispatcher;
typedef struct s_parser		t_parser;
typedef void				(*t_parser_fn)(t_parser *p);

struct s_dispatcher
{
	const char	*id;
	t_parser_fn	fn;
};

// dispatcher.c
void	dispatch_subparser(t_parser *p);

#endif
