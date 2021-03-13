/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:42:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/13 17:30:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	char	*line;
	int		counter;
	int		fd;
	int		gnl;

	line = (char *)malloc(SIZE_MAX);
	counter = 0;
	fd = open("TRoS.txt", O_RDONLY);
	gnl = 1;
	while (gnl <= 0 && counter <= 60)
	{
		counter++;
		printf("try: \e[1;31m%i\e[0m\n", counter);
		gnl = get_next_line(fd, &line);
		printf("\e[1;37m%s\e[0m\n", line);
	}
	printf("\e[32mConcluded!\e[0m\n");
	return (0);
}
