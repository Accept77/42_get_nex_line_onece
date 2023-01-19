/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:12 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/19 17:32:46 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_strlcpy(char *dst, char *src, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*gnl_cpy(char *buf, int index)
{
	int	i;
	char *result;

	i = 0;
	result = (char *)malloc(sizeof(char) * index);
	if (!result)
		return (NULL);
	while (i < index)
	{
		result[i] = buf[i];
		i++;
	}
	return(result);
}

char	*gnl_cpy_result(char *buf, int index)
{
	int i;
	char *result;

	i = 0;
	result = (char *)malloc(sizeof(char) * (index + 1));
	if (!result)
		return (NULL);
	while (i < index)
	{
		result[i] = buf[i];
		i++;
	}
	result[i] = '\0';
	return(result);
}

char	*gnl_join(char *stay, char *buf, int index, int index_stay)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (index_stay + index));
	if (!result)
		return (NULL);
	ft_strlcpy(result, stay, index_stay);
	ft_strlcpy(result + index_stay, buf, index);
	return (result);
}
