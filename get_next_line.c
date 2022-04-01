/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrha <hrha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:58:10 by hrha              #+#    #+#             */
/*   Updated: 2022/04/01 22:01:08 by hrha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd) {
    char			*str;
    static	char	*backup;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	str = get_str(fd, backup);
	return (str);
}

char	*get_str(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		flag;
	char	*front;

	flag = 1;
	while (!check_nl(str) && flag != 0) 
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag < -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	front = split_str(str);
	return (front);
}

char	*split_str(char *str)
{
	int		i;
	int		j;
	char	*head;
	char	*tail;

	i = 0;	
	while (str[i] != '\n')
		i++;
	j = ft_strlen(str) - i - 1;
	head = (char *)malloc(sizeof(char) * (i + 2));
	if (!head)
		return (NULL);
	tail = (char *)malloc(sizeof(char) * (j + 1));
	if (!tail)
		return (NULL);
	ft_strlcpy(head, str, i + 2);
	ft_strlcpy(tail, str + i + 2, j + 1);
	free(str);
	str = tail;
	return (head);
}
