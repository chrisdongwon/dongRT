/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:32:02 by cwon              #+#    #+#             */
/*   Updated: 2025/09/11 11:50:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "../libft.h"

static char	*flush_gnl(char **remaining, char *buffer, bool success)
{
	char	*result;

	result = NULL;
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (remaining && *remaining)
	{
		if (success)
			result = ft_substr(*remaining, 0, ft_strlen(*remaining));
		free(*remaining);
		*remaining = NULL;
	}
	return (result);
}

static char	*extract_remaining(char *remaining, char *buffer)
{
	char	*result;
	char	*temp;

	if (!remaining && buffer)
		return (ft_substr(buffer, 0, ft_strlen(buffer)));
	temp = ft_substr(remaining, 0, ft_strlen(remaining));
	if (!temp)
		return (flush_gnl(&remaining, 0, false));
	result = ft_strjoin(temp, buffer);
	flush_gnl(&remaining, temp, false);
	return (result);
}

static char	*update_remaining(char *remaining)
{
	char	*result;
	ssize_t	i;

	if (!remaining)
		return (0);
	i = ft_indexof(remaining, '\n');
	if (!remaining[i + 1])
		return (flush_gnl(&remaining, 0, false));
	result = ft_substr(remaining, i + 1, ft_strlen(remaining));
	flush_gnl(&remaining, 0, false);
	return (result);
}

static char	*extract_line(int fd, char *buffer, char **remaining)
{
	char	*result;
	ssize_t	bytes_read;
	ssize_t	end;

	bytes_read = -1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (!bytes_read && !*remaining))
			return (flush_gnl(remaining, buffer, false));
		buffer[bytes_read] = 0;
		*remaining = extract_remaining(*remaining, buffer);
		end = ft_indexof(*remaining, '\n');
		if (end != -1)
		{
			result = ft_substr(*remaining, 0, end + 1);
			if (!result)
				return (flush_gnl(remaining, buffer, false));
			*remaining = update_remaining(*remaining);
			free(buffer);
			return (result);
		}
	}
	return (flush_gnl(remaining, buffer, true));
}

bool	get_next_line(int fd, char **result)
{
	char		*buffer;
	static char	*remaining;

	if (fd < 0)
	{
		flush_gnl(&remaining, 0, false);
		return (false);
	}
	if (BUFFER_SIZE <= 0 || !result)
	{
		flush_gnl(&remaining, 0, false);
		return (false);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		flush_gnl(&remaining, 0, false);
		return (false);
	}
	*result = extract_line(fd, buffer, &remaining);
	return (*result != NULL);
}

// char	*get_next_line(int fd)
// {
// 	char		*buffer;
// 	static char	*remaining;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (flush_gnl(&remaining, 0, 0));
// 	buffer = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (flush_gnl(&remaining, 0, 0));
// 	return (extract_line(fd, buffer, &remaining));
// }
