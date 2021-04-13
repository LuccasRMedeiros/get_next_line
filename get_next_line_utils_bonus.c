/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:16:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/17 11:07:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gnl_ prefix are for special editions of libft functions used in this project
*/

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strdup(const char *str)
{
	int		str_size;
	char	*ret;
	size_t	i;

	str_size = ft_strlen(str);
	ret = (char*)malloc((str_size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	find;
	size_t			i;

	i = 0;
	find = (unsigned char)c;
	while (str[i] != find)
	{
		if (str[i] == '\0' && find != '\0')
			return (NULL);
		i++;
	}
	return ((char*)str + i);
}

char	*ft_reallocncat(char *dst, char const *src)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	char	*temp;
	size_t	alloc;

	if (!dst || !src)
		return (NULL);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	temp = gnl_strdup(dst);
	alloc = dst_len + src_len + 1;
	free(dst);
	dst = NULL;
	if (!(dst = (char*)malloc(sizeof(char) * alloc)))
		return (NULL);
	while (i < alloc - 1)
	{
		dst[i] = (i < dst_len ? temp[i] : src[i - dst_len]);
		i++;
	}
	free(temp);
	dst[i] = '\0';
	return (dst);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	stti;
	size_t	subi;
	char	*sub;

	if (!s)
		return (NULL);
	stti = (size_t)start;
	subi = 0;
	if (!(sub = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start >= ft_strlen(s))
		return (sub);
	while (subi < len && s[stti])
	{
		sub[subi] = s[stti];
		stti++;
		subi++;
	}
	sub[subi] = '\0';
	return (sub);
}
