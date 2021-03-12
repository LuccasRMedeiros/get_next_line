/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/11 21:34:52 by lrocigno         ###   ########.fr       */
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

static int	read_file(int fd, char *buf, char *rf)
{
	int	n;

	n = 1;
	while (n && !(ft_strchr(buf, '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0 || n > BUFFER_SIZE)
			return (0);
		buf[n] = '\0';
		rf = ft_reallocncat(rf, buf);
	}
	printf("rf address: \e[1;35m%p\e[0m\n", rf);
	return (1);
}

static void	next_line(char *rf, char **line)
{
	size_t	i;

	i = 0;
	while (rf[i] != '\n' || rf[i] != '\0')
		i++;
	*line = (rf[i] == '\n' ? gnl_substr(rf, 0, i) : gnl_strdup(rf));
}

static int	hunter(int fd, char *buf, char **rf)
{
	if (fd < 0 || fd > RLIMIT_NOFILE)
	{
		printf("Problem encountered with fd value (\e[1;32m%i\e[0m\n", fd);
		return (1);
	}
	else if (BUFFER_SIZE <= 0)
	{
		printf("\e[1;31merror: \e[0mBUFFER_SIZE should be greater than zero.\n");
		return (1);
	}
	else if (!buf)
	{
		printf("Malloc could not fetch the solicited amount of memory.\n");
		return (1);
	}
	else if (!(read_file(fd, buf, rf)))
	{
		printf("\e[1;31error: \e[0mRead can't read from file");
		return (1);
	}
	printf("rf address: \e[1;35m%p\e[0m\n", rf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*rf;
	char		*buffer;

	if (!rf)
		rf = gnl_strdup("");
	printf("rf address: \e[1;35m%p\e[0m\n", rf);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (hunter(fd, buffer, &rf))
		return (-1);
	free(buffer);
	next_line(rf, line);
	free(rf);
	return 0;
}

int	main()
{
	char *content = (char*)malloc(sizeof(char) * 2495);
	int	fd = open("TRoS.txt", O_RDONLY, 0);
	int	gnl = get_next_line(fd, &content);

	printf("gnl: \e[1;32m%i\e[0m\n", gnl);
	free(content);
	return 0;
}
