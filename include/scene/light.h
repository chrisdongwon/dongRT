/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:26 by cwon              #+#    #+#             */
/*   Updated: 2025/10/19 15:00:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "vector.h"

typedef enum e_light_type	t_light_type;
typedef struct s_light		t_light;
typedef struct s_list		t_list;

struct						s_list;

enum e_light_type
{
	AMBIENT,
	POINT
};

struct s_light
{
	double			intensity;
	t_color			color;
	t_light_type	type;
	t_vector		pos;
};

t_light	*new_light(t_light_type type, t_vector v, t_color c, double intensity);

#endif
