/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:34:56 by cwon              #+#    #+#             */
/*   Updated: 2025/11/06 12:07:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>

typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;	
};

bool	is_normalized(t_vector v);
double	norm(t_vector v);

#endif
