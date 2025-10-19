/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:01:49 by cwon              #+#    #+#             */
/*   Updated: 2025/09/19 10:51:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H

# include <stdbool.h>

# include "quadratic.h"

typedef struct s_interval	t_interval;

struct s_interval
{
	double	min;
	double	max;
};

bool	in_interval(double t, t_interval range);
double	closest_root_in_range(t_quadratic solution, t_interval range);

#endif
