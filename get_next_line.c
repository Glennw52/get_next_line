/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:15 by gwinnink          #+#    #+#             */
/*   Updated: 2021/12/14 14:01:29 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*read_into_buff(int fd, char *buff)
{
	char	*temp;
	int		b_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	b_read = 1;
	while (!ft_strchr(buff, '\n') && b_read != 0)
	{
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[b_read] = '\0';
		buff = ft_strjoin(buff, temp);
	}
	free(temp);
	return (buff);
}

char	*separate_line(char *buff)
{
	char	*ret_line;
	int		i;

	if (!*buff)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	ret_line = (char *)malloc(i + 1);
	if (!ret_line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		ret_line[i] = buff[i];
		i++;
	}
	ret_line[i] = buff[i];
	if (buff[i])
		ret_line[i + 1] = '\0';
	return (ret_line);
}

char	*separate_rest(char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	temp = (char *)malloc(ft_strlen(buff) - i + 1);
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (buff[i + j])
	{
		temp[j] = buff[i + j];
		j++;
	}
	temp[j] = '\0';
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_into_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = separate_line(buff);
	buff = separate_rest(buff);
	return (line);
}
