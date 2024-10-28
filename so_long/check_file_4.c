/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:04:16 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/06 15:38:25 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_copy(char **map, t_long *data)
{
	char	**map_copy;
	int		y;

	y = 0;
	map_copy = ft_calloc(data->y + 1, sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (y < data->y)
	{
		map_copy[y] = ft_calloc(data->x + 1, sizeof(char));
		if (!map_copy[y])
		{
			free_double(map_copy);
			return (NULL);
		}
		ft_strlcpy(map_copy[y], map[y], data->x + 1);
		y++;
	}
	return (map_copy);
}

int	good_floodfill(char **map, char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'E' && map_copy[y][x] != 'A') \
				|| (map[y][x] == 'C' && map_copy[y][x] != 'A'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
