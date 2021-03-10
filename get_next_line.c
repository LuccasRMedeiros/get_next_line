/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/10 00:57:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Uses "read" function to read a file, then starts to read line per line.
** Grants information perservation during all the execution usign static vars.
** Read function returns the size of the file read.
** Buf pointer receives the text read, limited by the nbyte argument.
** Read continues to advance through the document as many times it is called.
*/

int	get_next_line(int fd, char **line)
{
	static char	*rline;
	size_t		b;
	size_t		i;

	printf("fd: \e[1;32m%i\e[0m\n", fd);
	b = read(fd, *line, 100); // Fixed value for testing purposes
	printf("\e[1;37m%s\e[0m\n", *line);
	i = 0;
	while (i <= b && (*line[i] != '\n' && *line[i] != '\0'))
	{
		printf("*line[\e[1;35m%zu\e[0m]: \e[1;33m%i\e[0m\n", i, *line[i]);
		i++;
	}
	printf("i: \e[1;32m%zu\e[0m\n", i);
	if (*line[i] == '\0')
	{
		printf("Found the end of file\n");
		return (0);
	}
	else if (!(rline = malloc(sizeof(char) * i)))
	{
		printf("malloc didn't managed to allocate memory\n");
		return (-1);
	}
	while (i >= 0)
	{
		printf("Entered last while loop\n");
		rline[i] = *line[i];
		i--;
	}
	printf("i: \e[1;32m%zu\e[0m\n", i);
	free(rline);
	printf("Freed \e[1;35mrline\e[0m\n");
	return (1);
}

int	main()
{
	char *content = (char*)malloc(sizeof(char) * 2149);
	int	fd = open("TRoS.txt", O_RDONLY, 0);
	int	sz = read(fd, content, 100);
	int	i;

	printf("\e[1;37m%s\e[0m\nsize: \e[1;32m%i\e[0m\n", content, sz);
	for (i = 0; i <= 21; i += 1)
	{
		sz = read(fd, content, 100);
		printf("\e[1;35mTime %i\e[0m:\n\e[1;37m%s\e[0m\n", i, content);
	}

	int	gnl = get_next_line(fd, &content);

	printf("\e[1;37m%s\e[0m\nsize: \e[1;32m%i\e[0m\n", content, gnl);
	free(content);
	return 0;
}
