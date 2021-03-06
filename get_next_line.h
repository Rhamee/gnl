/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrha <hrha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:57:58 by hrha              #+#    #+#             */
/*   Updated: 2022/04/09 21:54:01 by hrha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*get_backup(int fd, char *backup);
char	*split_str(char *backup);
char	*get_remain(char *backup);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		check_nl(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
