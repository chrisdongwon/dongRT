/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:09:09 by cwon              #+#    #+#             */
/*   Updated: 2025/10/25 17:15:30 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"
#include "miniRT.h"
#include "scene.h"

static char	*trim_line(char *line, t_scene *scene)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, "\t\n\v\f\r ");
	free(line);
	if (trimmed == NULL)
		error_exit("ft_strtrim", strerror(errno), scene);
	return (trimmed);
}

void	parse_lines(int fd, t_scene *scene)
{
	char	*line;
	t_list	*list;

	while (get_next_line(fd, &line))
	{
		line = trim_line(line, scene);
		if (*line != '\0')
		{
			list = split_line(line, scene);
			parse_list(list, scene);
			ft_lstclear(&list, free);
		}
		free(line);
	}
}
