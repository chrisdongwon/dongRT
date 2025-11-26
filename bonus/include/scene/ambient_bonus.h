/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:58:18 by cwon              #+#    #+#             */
/*   Updated: 2025/11/26 13:41:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_BONUS_H
# define AMBIENT_BONUS_H

# include "color_bonus.h"

typedef struct s_ambient	t_ambient;

struct s_ambient
{
	double	ratio;
	t_color	color;
};

#endif
