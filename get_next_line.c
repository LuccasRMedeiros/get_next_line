/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/08 15:47:25 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Uses "read" function to read a file, then starts to read line per line.
** Grants information persistation during all the execution usign static vars.
*/

int	get_next_line(int fd, char **line)
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
}
