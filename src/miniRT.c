/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:15:21 by cwon              #+#    #+#             */
/*   Updated: 2025/09/05 12:24:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "parser.h"

static void	usage_message(char **argv)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putstr_fd(" <file.rt>\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	mini_rt(const int argc, char **argv)
{
	if (argc != 2)
		usage_message(argv);
	parse(argv[1]);
	ft_printf("Scene parsed successfully!\n");
}
