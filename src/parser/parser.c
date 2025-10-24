/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:42:30 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 15:51:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"
#include "miniRT.h"
#include "scene.h"

void	parse(const int argc, char **argv, t_scene *scene)
{
	//char	**tokens; // or, linked list?
	char	*line;
	int		fd;

	validate_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(argv[1], strerror(errno), 0);
	while (get_next_line(fd, &line))
	{
		ft_printf("%s", line);
	// 	tokens = ft_split_ws(line);
	// 	parse_line(scene, tokens);
	// 	free_split(tokens);
		free(line);
	}
	close(fd);
	// validate_scene(scene);
}
