/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:46:37 by cwon              #+#    #+#             */
/*   Updated: 2025/11/07 15:16:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include <color.h>
# include <stdbool.h>
# include <vector.h>

typedef struct s_hit	t_hit;

struct s_hit
{
	bool		hit;
	double		t;
	t_color		color;
	t_vector	normal;
	t_vector	point;
};

#endif
