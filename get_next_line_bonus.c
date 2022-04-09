/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrha <hrha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:49:11 by hrha              #+#    #+#             */
/*   Updated: 2022/04/09 22:04:54 by hrha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*str;
	static char		*backup[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	backup[fd] = get_backup(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	str = split_str(backup[fd]);
	backup[fd] = get_remain(backup[fd]);
	return (str);
}

char	*get_backup(int fd, char *backup)
{
	char	*buffer;
	int		flag;

	flag = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!check_nl(backup) && flag != 0)
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*split_str(char *backup)
{
	int		i;
	char	*head;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	head = (char *)malloc(sizeof(char) * (i + 2));
	if (!head)
		return (NULL);
	ft_strlcpy(head, backup, i + 2);
	return (head);
}

char	*get_remain(char *backup)
{
	char	*tail;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	j = ft_strlen(backup) - i - 1;
	tail = (char *)malloc(sizeof(char) * (j + 1));
	if (!tail)
		return (NULL);
	ft_strlcpy(tail, backup + i + 1, j + 1);
	free(backup);
	return (tail);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((char *)b + i) = c;
		i++;
	}
	return (b);
}
