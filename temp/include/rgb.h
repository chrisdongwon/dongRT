/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:53:53 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 07:48:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

# include <stdbool.h>

typedef struct s_rgb	t_rgb;

struct s_rgb
{
	int	r;
	int	g;
	int	b;
};

bool	is_valid_rgb(t_rgb *color);
void	init_rgb(t_rgb *color, int r, int g, int b);
void	print_rgb(t_rgb *color);

#endif
