/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:49:28 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/07 11:10:39 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_file(char *file, t_long *data)
{
	char	**map;

	if (check_ber(file) == 1)
	{
		ft_printf("Erreur : fichier invalide\n");
		return (NULL);
	}
	map = display_map(file);
	if (map == NULL)
	{
		ft_printf("Erreur : parsing incorrect\n");
		return (NULL);
	}
	if (check_map(map, data) == 1)
	{
		ft_printf("Erreur : map invalide\n");
		free_double(map);
		return (NULL);
	}
	return (map);
}

int	check_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i <= 4)
		return (1);
	if (ft_strncmp(&file[i - 4], ".ber", 10) != 0)
		return (1);
	return (0);
}

int	check_map(char **map, t_long *data)
{
	if (is_it_square(map, data) == 1)
		return (1);
	if (check_line(map, data) == 1)
		return (1);
	if (check_symbol(map, data) == 1)
		return (1);
	if (floodfill(map, data) == 1)
	{
		ft_printf("Aucun chemin possible\n");
		free_double(map);
		exit(EXIT_FAILURE);
	}
	return (0);
}

char	**display_map(char *file)
{
	char	**map;
	char	*line;
	int		len;
	int		fd;

	len = 0;
	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		error_fd();
	if (read(fd, 0, 0) < 0)
		error_fd_2(fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	close(fd);
	if (len < 3)
		return (NULL);
	map = ft_calloc(len + 1, sizeof(char *));
	if (!map)
		exit(EXIT_FAILURE);
	return (display_map_2(map, file, len));
}

char	**display_map_2(char **map, char *file, int len)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		error_fd();
	while (i <= len)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map[i])
		{
			close(fd);
			error_fd_3(map, i);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
