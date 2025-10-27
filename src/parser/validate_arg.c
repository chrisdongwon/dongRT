/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:54:04 by cwon              #+#    #+#             */
/*   Updated: 2025/10/27 14:20:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "mini_rt.h"

static bool	has_rt_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len > 3 && ft_strcmp(filename + len - 3, ".rt") == 0);
}

static void	usage_message(void)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd("miniRT", STDERR_FILENO);
	ft_putendl_fd(" <scene.rt>", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	validate_arg(const int argc, char **argv)
{
	if (argc != 2)
		usage_message();
	if (!has_rt_extension(argv[1]))
		mini_rt_error(argv[1], "file must have .rt extension", 0);
}
