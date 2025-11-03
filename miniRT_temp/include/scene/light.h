/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:26 by cwon              #+#    #+#             */
/*   Updated: 2025/10/30 15:31:31 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "vector.h"

typedef struct s_light	t_light;

struct s_light
{
	double			intensity;
	t_color			color;
	t_vector		pos;
};

t_light	*new_light(t_vector v, t_color c, double intensity);

#endif
