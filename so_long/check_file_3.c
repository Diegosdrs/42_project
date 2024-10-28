/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:03 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/06 15:46:07 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_symbol(char **map, t_long *data)
{
	int	x;
	int	y;

	data->p = 0;
	data->e = 0;
	data->c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				data->p++;
			if (map[y][x] == 'E')
				data->e++;
			if (map[y][x] == 'C')
				data->c++;
			x++;
		}
		y++;
	}
	if (data->p != 1 || data->e != 1 || data->c < 1)
		return (1);
	return (0);
}

int	floodfill(char **map, t_long *data)
{
	char	**map_copy;
	t_long	p;

	map_copy = create_copy(map, data);
	find_p(map_copy, &p);
	dfs(map_copy, p.y, p.x, data);
	if (good_floodfill(map, map_copy) == 1)
	{
		free_double(map_copy);
		return (1);
	}
	free_double(map_copy);
	return (0);
}

int	dfs(char **map_copy, int y, int x, t_long *data)
{
	if (y < 0 || y >= data->y || x < 0 || x >= data->x \
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'A')
		return (0);
	map_copy[y][x] = 'A';
	dfs(map_copy, y + 1, x, data);
	dfs(map_copy, y - 1, x, data);
	dfs(map_copy, y, x + 1, data);
	dfs(map_copy, y, x - 1, data);
	return (0);
}

void	find_p(char **map, t_long *p)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				p->x = x;
				p->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
