/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:38 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/12 12:50:12 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static inline void	_reduce_buffer(
	char *const buffer,
	ssize_t *const size_buffer,
	size_t const offset)
{
	ft_memcpy(buffer, buffer + offset, *size_buffer - offset);
	*size_buffer -= offset;
}

static inline char	*_join_buff(
	char const *const line,
	ssize_t *const len_line,
	char const *const buffer,
	ssize_t const len_buffer)
{
	char	*ret;

	ret = malloc(*len_line + len_buffer + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, line, *len_line);
	ft_memcpy(ret + *len_line, buffer, len_buffer);
	ret[*len_line + len_buffer] = '\0';
	*len_line += len_buffer;
	return (ret);
}

static inline char	*_read_line(
	char *line,
	int const fd,
	char *const buffer,
	ssize_t *sizes)
{
	char	*temp;
	char	*p;

	sizes[0] = read(fd, buffer, BUFFER_SIZE);
	while (sizes[0] > 0)
	{
		temp = line;
		p = ft_strnchr(buffer, '\n', sizes[0]);
		if (p)
			line = _join_buff(line, &sizes[1], buffer, p - buffer + 1);
		else
			line = _join_buff(line, &sizes[1], buffer, sizes[0]);
		free(temp);
		if (line == NULL)
			return (NULL);
		if (p)
			return (_reduce_buffer(buffer, &sizes[0], p - buffer + 1), line);
		if (sizes[0] < BUFFER_SIZE)
			return (sizes[0] = 0, line);
		sizes[0] = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int const fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	sizes[2];
	char			*line;
	char			*index;

	if (fd < 0)
		return (NULL);
	line = NULL;
	sizes[1] = 0;
	if (sizes[0] > 0)
	{
		index = ft_strnchr(buffer, '\n', sizes[0]);
		if (index)
		{
			line = _join_buff(NULL, &sizes[1], buffer, index - buffer + 1);
			_reduce_buffer(buffer, &sizes[0], index - buffer + 1);
			return (line);
		}
		line = _join_buff(NULL, &sizes[1], buffer, sizes[0]);
		sizes[0] = 0;
	}
	line = _read_line(line, fd, buffer, sizes);
	return (line);
}
