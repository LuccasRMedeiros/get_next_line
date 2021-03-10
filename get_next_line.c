/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/09 16:51:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Uses "read" function to read a file, then starts to read line per line.
** Grants information persistence during all the execution usign static vars.
*/

/*int	get_next_line(int fd, char **line)
{
	static char	*rline;
	size_t		b;
	size_t		i;

	b = read(fd, *line, BUFFER_SIZE);
	i = 0;
	while (i <= b)
	{
		rline[i] = *line[i];
		if (rline[i] == '\n')
			return (1);
		if (!(rline[i] || rline))
			return (0);
	}
	return (0);
}*/

int	main()
{
	char *content = (char*)malloc(sizeof(char) * 2149);
	int	fd = open("TRoS.txt", O_RDONLY, 0);
	int sz = read(fd, content, 2149);

	printf("sz: \e[1;32m%i\e[0m\n", sz);
	printf("\e[1;37m%s\e[0m\n", content);
	return 0;
}
