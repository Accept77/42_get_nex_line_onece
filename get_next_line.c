/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/19 18:14:29 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*result = NULL;
	char		buf[BUFFER_SIZE];
	static	char	*stay;
	int index = 1;
	int index_stay = 0;
	char		*tmp;
	int i = 0;

	if (!stay)
	{
		while (index != 0)
		{
			index = read(fd, buf, BUFFER_SIZE);
			if (index < 0)
			{
				free(stay);
				stay = NULL;
				return (NULL);
			}
			else if(index == 0)
				break ;
			if (!stay)
				stay = gnl_cpy(buf, index);
			else
			{
				tmp = gnl_cpy(stay, index_stay);
				free(stay);
				stay = NULL;
				stay = gnl_join(tmp, buf, index, index_stay);
				free(tmp);
				tmp = NULL;
			}
			index_stay += index;
		}
		if (stay == NULL)
			return (NULL);
		while(i < index_stay)
		{
			if (stay[i] == '\n')
			{
				i++;
				break;
			}
			i++;
		}
		result = gnl_cpy_result(stay, i);
		tmp = gnl_cpy(stay + i, index_stay - i);
		free(stay);
		stay = gnl_cpy_result(tmp, index_stay - i);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		if (stay[0] == '\0')
		{
			free(stay);
			stay = NULL;
			return (NULL);
		}
		index_stay = gnl_strlen(stay);
		while(i < index_stay)
		{
			if (stay[i] == '\n')
			{
				i++;
				break;
			}
			i++;
		}
		result = gnl_cpy_result(stay, i);
		tmp = gnl_cpy(stay + i, index_stay - i);
		free(stay);
		stay = gnl_cpy_result(tmp, index_stay - i);
		free(tmp);
		tmp = NULL;
	}
	return (result);
}
