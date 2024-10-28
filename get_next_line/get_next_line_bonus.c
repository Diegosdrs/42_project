/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:49:06 by dsindres          #+#    #+#             */
/*   Updated: 2024/06/12 14:45:35 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_buff(char	*tempbuff, char *buffer)
{
	char	*new_tempbuff;

	new_tempbuff = ft_strjoin(tempbuff, buffer);
	if (!new_tempbuff)
		return (NULL);
	free(tempbuff);
	return (new_tempbuff);
}

char	*next_line(char	*tempbuff)
{
	int		i;
	int		j;
	char	*new_tempbuff;

	i = 0;
	j = 0;
	while (tempbuff[i] && tempbuff[i] != '\n')
		i++;
	if (!tempbuff[i])
		return (free (tempbuff), (NULL));
	new_tempbuff = ft_calloc((ft_strlen(tempbuff) - i + 1), sizeof(char));
	if (!new_tempbuff)
		return (NULL);
	i++;
	j = 0;
	while (tempbuff[i])
		new_tempbuff[j++] = tempbuff[i++];
	new_tempbuff[j++] = '\0';
	free (tempbuff);
	return (new_tempbuff);
}

char	*good_line(char *tempbuff)
{
	char	*line;
	int		i;

	i = 0;
	if (!tempbuff[i])
		return (NULL);
	while (tempbuff[i] && tempbuff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (tempbuff[i] && tempbuff[i] != '\n')
	{
		line[i] = tempbuff[i];
		i++;
	}
	if (tempbuff[i] && tempbuff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read(char *tempbuff, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!tempbuff)
		tempbuff = ft_calloc (1, 1);
	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	while (!is_n(buffer) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		tempbuff = free_buff(tempbuff, buffer);
	}
	free (buffer);
	return (tempbuff);
}

char	*get_next_line(int fd)
{
	static char	*tempbuff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (tempbuff[fd])
		{
			free (tempbuff[fd]);
			tempbuff[fd] = NULL;
		}
		return (NULL);
	}
	tempbuff[fd] = ft_read(tempbuff[fd], fd);
	if (!tempbuff[fd])
		return (NULL);
	line = good_line(tempbuff[fd]);
	tempbuff[fd] = next_line(tempbuff[fd]);
	return (line);
}
