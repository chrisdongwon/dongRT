/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:58:47 by cwon              #+#    #+#             */
/*   Updated: 2025/09/06 19:35:00 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "rgb.h"

typedef struct s_ambient	t_ambient;

struct s_ambient
{
	float	ratio;
	t_rgb	color;
};

#endif
