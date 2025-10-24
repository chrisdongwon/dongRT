/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:06:59 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 15:42:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_scene	t_scene;
struct					s_scene;

// parser_validate.c
void	validate_arg(const int argc, char **argv);

// parser.c
void	parse(const int argc, char **argv, t_scene *scene);

#endif
