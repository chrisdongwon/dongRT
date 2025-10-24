/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:29:20 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 15:43:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_scene	t_scene;
struct					s_scene;

void	error_exit(const char *context, const char *msg, t_scene *scene);
void	mini_rt(const int argc, char **argv);

#endif
