/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:31:00 by cwon              #+#    #+#             */
/*   Updated: 2025/10/24 12:40:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

bool	has_rt_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len > 3 && ft_strcmp(filename + len - 3, ".rt") == 0);
}

char	*trim_whitespace(char *str)
{
	char	*end;

	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '\0')
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

int	get_tokens(char *tokens[MAX_TOKENS], char *line)
{
	char	*tok;
	int		count;

	count = 0;
	tok = ft_strtok(line, " \t");
	while (tok)
	{
		if (count >= MAX_TOKENS)
			return (-1);
		tokens[count++] = tok;
		tok = ft_strtok(NULL, " \t");
	}
	return (count);
}

void	fatal(const char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	usage_message(char **argv)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putendl_fd(" <scene.rt>", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
