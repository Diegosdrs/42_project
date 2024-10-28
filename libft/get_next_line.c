/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:21:02 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/24 11:17:28 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			return (free(buffer), (NULL));
		buffer[bytes_read] = '\0';
		tempbuff = free_buff(tempbuff, buffer);
	}
	free (buffer);
	return (tempbuff);
}

char	*get_next_line(int fd)
{
	static char	*tempbuff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (tempbuff)
		{
			free (tempbuff);
			tempbuff = NULL;
		}
		return (NULL);
	}
	tempbuff = ft_read(tempbuff, fd);
	if (!tempbuff)
		return (NULL);
	line = good_line(tempbuff);
	tempbuff = next_line(tempbuff);
	return (line);
}
