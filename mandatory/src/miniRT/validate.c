/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:33:18 by cwon              #+#    #+#             */
/*   Updated: 2025/11/14 12:47:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

static bool	has_extension(const char *filename, const char *ext)
{
	size_t	len_ext;
	size_t	len_file;

	len_file = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_file < len_ext)
		return (0);
	return (ft_strcmp(filename + len_file - len_ext, ext) == 0);
}

static void	validate_error(const char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	validate_arg(int argc, char **argv)
{
	if (argc != 2)
		validate_error("usage: miniRT <scene.rt>");
	if (!has_extension(argv[1], ".rt"))
		validate_error("miniRT: Scene file must have .rt extension");
}
