/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/10 15:42:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/resource.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

//this include is to be erased after the code be finished
# include <stdio.h>

char    *ft_strchr(const char *str, int c);
int		get_next_line(int fd, char **line);

#endif
