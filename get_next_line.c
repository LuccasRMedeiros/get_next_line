/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/10 12:38:15 by lrocigno         ###   ########.fr       */
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
** - file descriptor called in arguments don't have nothing to be read
** - **line is (null)
** - read function returned error (-1)
** - malloc function could not allocate memory
*/

int	get_next_line(int fd, char **line)
{
	char	*rline;
	size_t	b;
	size_t	i;

	b = read(fd, rline, 2495); // Fixed value for testing purposes
	i = 0;
	while (i <= b && (line[0][i] != '\n' && line[0][i] != '\0'))
	{
		i++;
	}
	if (line[0][i] == '\0')
	{
		return (0);
	}
	else if (!(rline = malloc(sizeof(char) * i)))
	{
		return (-1);
	}
	while (i > 0)
	{
		rline[i] = line[0][i];
		i--;
	}
	free(rline);
	return (1);
}

int	main()
{
	char *content = (char*)malloc(sizeof(char) * 2495);
	int	fd = open("TRoS.txt", O_RDONLY, 0);
	int	gnl = get_next_line(fd, &content);

	printf("gnl: \e[1;32m%i\e[0m\ncontent:\n\e[1;37m%s\e[0m\n", gnl, content);
	free(content);
	return 0;
}
