/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:16:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/10 23:55:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*gnl_calloc(size_t n_itens, size_t size)
{
	void	*ret;

	if (!(temp = malloc(n_itens * size)))
		return (NULL);
	while (size)
	{
		*ret = 0;
		ret++;
		size--;
	}
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	join = malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len])
	{
		join[i] = s2[i - s1_len];
		i++;
	}
	join[i] = '\0';
	return (join);
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
	if (!(sub = ft_calloc(sizeof(char) * len + 1), len + 1))
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
