/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:16:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/10 15:38:02 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
