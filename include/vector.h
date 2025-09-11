/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:56:19 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 07:51:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>

typedef struct s_vector	t_vector;

struct s_vector
{
	float	x;
	float	y;
	float	z;
};

bool	is_normed(t_vector *vec);
void	print_vector(t_vector *vec);

#endif
