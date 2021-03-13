/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:12:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/13 16:43:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/param.h>
# include <sys/resource.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*gnl_strdup(char const *str);
char	*ft_strchr(const char *str, int c);
char	*ft_reallocncat(char *dst, char const *src);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
