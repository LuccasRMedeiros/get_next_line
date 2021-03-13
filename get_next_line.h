/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/12 19:44:11 by lrocigno         ###   ########.fr       */
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

size_t  ft_strlen(const char *str);
char    *gnl_strdup(char const *str);
char    *ft_strpchr(const char *str, int c);
char	*ft_reallocncat(char *dst, char const *src);
char    *gnl_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
