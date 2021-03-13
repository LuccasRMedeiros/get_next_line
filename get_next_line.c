/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/12 22:30:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Uses "read" function to read a file, then starts to read line per line.
** Grants information perservation during all the execution usign static vars.
** Read function returns the size of the file read.
** Buf pointer receives the text read, limited by the nbyte argument.
** Read continues to advance through the document as many times it is called.
** Line is the pointer that gonna be processed by get_next_line.
** get_next_line should return error (-1) when face some issues like
** - file descriptor called in arguments don't have nothing to be read;
** - file descriptor is invalid (less than zero, more than RLIMIT_NOFILE);
** - **line is (null);
** - read function returned error (-1);
** - malloc function could not allocate memory;
** After each read the next line should be ready to be read.
** "hunter" should tell what error has been found before the code be done.
** "hunter" returns 1 when it find an error and 0 when everything is fine to go.
** "read_file" will read the file in fd and return 1 for success and 0 for fail-
** the reason to read in a loop is due to the objective to get a line.
*/

static int	read_file(int fd, char *buf, char **rf)
{
	int	n;

	n = 1;
	while (n && !(ft_strpchr(*rf, '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0 || n > BUFFER_SIZE)
			return (n);
		*rf = ft_reallocncat(*rf, buf);
	}
	return (n);
}

static void	next_line(char **rf, char **line)
{
	size_t	i;
	char	*holder;

	i = 0;
	while (rf[0][i] != '\n' && rf[0][i] != '\0')
	{
		i++;
	}
	*line = gnl_substr(*rf, 0, i);
	holder = ft_strpchr(*rf, '\n');
	free(*rf);
	*rf = gnl_strdup("");
	*rf = ft_reallocncat(*rf, holder);
}

static int	hunter(int fd, char *buf, char **rf)
{
	int	nread;

	if (fd < 0 || fd > RLIMIT_NOFILE)
	{
		return (-1);
	}
	else if (BUFFER_SIZE <= 0)
	{
		return (-1);
	}
	else if (!buf)
	{
		return (-1);
	}
	nread = read_file(fd, buf, rf);
	return (nread);
}

int	get_next_line(int fd, char **line)
{
	static char	*rf;
	int			nread;
	char		*buffer;

	if (!rf)
		rf = gnl_strdup("");
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	nread = hunter(fd, buffer, &rf);
	if (nread < 0)
		return (-1);
	free(buffer);
	next_line(&rf, line);
	if (!nread)
	{
		free(rf);
		return (0);
	}
	return (1);
}

int	main()
{
	char *content = (char*)malloc(sizeof(char) * 2495);
	int	fd = open("TRoS.txt", O_RDONLY, 0);
	int	gnl = 1;
	int	counter = 0;

	while (gnl && counter <= 39)
	{
		counter++;
		printf("counter: \e[1;31m%i\e[0m\n", counter);
		gnl = get_next_line(fd, &content);
		printf("line = \e[1;33m%s\e[0m\n", content);
	}
	free(content);
	return 0;
}
