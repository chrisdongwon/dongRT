/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:29:20 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 12:57:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define WIN_HEIGHT 600
# define WIN_WIDTH 800

typedef struct s_scene	t_scene;

struct					s_scene;

void	mini_rt_error(const char *context, const char *msg, t_scene *scene);
void	mini_rt(const int argc, char **argv);

#endif
