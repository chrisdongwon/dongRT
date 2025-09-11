/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:56:19 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 13:06:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

void	print_vector(t_vector *vec);

#endif
