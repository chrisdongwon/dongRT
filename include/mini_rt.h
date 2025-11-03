/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:05:45 by cwon              #+#    #+#             */
/*   Updated: 2025/11/03 22:12:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

typedef struct s_scene	t_scene;

// mini_rt.c
void	mini_rt_error(t_scene *scene);
void	mini_rt(const int argc, char **argv);

// validate.c
void	validate_arg(const int argc, char **argv);

#endif
