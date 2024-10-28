/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:26:17 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/06 15:40:34 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_square(char **map, t_long *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	if (y == x || x + y < 8)
		return (1);
	data->x = x;
	data->y = y;
	return (is_it_square_2(map, data));
}

int	is_it_square_2(char **map, t_long *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != data->x)
			return (1);
		y++;
	}
	return (0);
}

int	check_line(char **map, t_long *data)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (1);
		x++;
	}
	if (middle_line(map, data) == 1)
		return (1);
	return (0);
}

int	middle_line(char **map, t_long *data)
{
	int	count_x;
	int	count_y;

	count_y = 0;
	while (count_y++ <= data->y - 2)
	{		
		if (map[count_y][0] != '1')
			return (1);
		count_x = 0;
		while (count_x++ <= data->x - 2)
		{
			if (map[count_y][count_x] != 'P'\
				&& map[count_y][count_x] != 'E'\
				&& map[count_y][count_x] != 'C'\
				&& map[count_y][count_x] != '1'\
				&& map[count_y][count_x] != '0')
				return (1);
		}
		if (map[count_y][data->x - 1] != '1')
			return (1);
	}
	if (last_line(map, data) == 1)
		return (1);
	return (0);
}

int	last_line(char **map, t_long *data)
{
	int	count_x;

	count_x = 0;
	while (map[data->y - 1][count_x])
	{
		if (map[data->y - 1][count_x] != '1')
			return (1);
		count_x++;
	}
	return (0);
}
