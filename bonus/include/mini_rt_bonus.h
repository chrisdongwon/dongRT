/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:46:14 by cwon              #+#    #+#             */
/*   Updated: 2025/11/25 14:47:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_BONUS_H
# define MINI_RT_BONUS_H

# define WIDTH 800
# define HEIGHT 600

typedef struct s_scene	t_scene;

// mini_rt_bonus.c
void	mini_rt_error(t_scene *scene);
void	mini_rt(int argc, char **argv);

// validate_bonus.c
void	validate_arg(int argc, char **argv);

#endif
