/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:22 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/19 17:33:36 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*gnl_cpy(char *buf, int index);
char	*gnl_join(char *stay, char *buf, int index, int index_stay);
size_t	gnl_strlen(const char *str);
char	*gnl_cpy(char *buf, int index);
char	*gnl_cpy_result(char *buf, int index);

#endif
