/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:56:19 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 10:07:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_vector	t_vector;

struct s_vector
{
	float	x;
	float	y;
	float	z;
};

bool	is_normed(t_vector *vec);
size_t	split_vector_str(char *str, char **out);
void	print_vector(t_vector *vec);

#endif
