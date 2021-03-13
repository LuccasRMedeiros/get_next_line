/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/13 15:22:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, char *buf, char **rf)
{
	int	n;

	n = 1;
	while (n && !(ft_strchr(*rf, '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0 || n > BUFFER_SIZE)
			return (n);
		buf[n] = '\0';
		*rf = ft_reallocncat(*rf, buf);
	}
	return (n);
}

static char	*next_line(char *rf, char **line, int nbytes)
{
	size_t	i;
	char	*holder;

	i = 0;
	holder = NULL;
	while (rf[i] != '\n' && rf[i] != '\0')
		i++;
	if (rf[i] == '\n')
	{
		*line = gnl_substr(rf, 0, i);
		holder = gnl_strdup(rf + (i + 1));
	}
	else
		*line = gnl_strdup(rf);
	free(rf);
	if (nbytes != 0)
		if (!holder)
			return (NULL);
	return (holder);
}

static int	error_catcher(int fd, char **line, char *buf, char **rf)
{
	int	nread;

	if (fd < 0 || fd > RLIMIT_NOFILE)
		return (-1);
	else if (!line)
		return (-1);
	else if (BUFFER_SIZE <= 0)
		return (-1);
	else if (!buf)
		return (-1);
	if (!*rf)
		*rf = gnl_strdup("");
	nread = read_file(fd, buf, rf);
	return (nread);
}

int			get_next_line(int fd, char **line)
{
	static char	*rf;
	int			nread;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	nread = error_catcher(fd, line, buffer, &rf);
	free(buffer);
	if (nread < 0)
		return (-1);
	rf = next_line(rf, line, nread);
	if (!nread)
		return (0);
	return (1);
}
