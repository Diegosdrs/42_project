/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:36:44 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/06 15:49:45 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image(t_long *data)
{
	display_structure(data);
	display_others(data);
	return (1);
}

int	display_structure(t_long *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_connection,
					data->window, data->img_wall, x * WIDTH, y * HEIGHT);
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_connection,
					data->window, data->img_back, x * WIDTH, y * HEIGHT);
			x++;
		}
		y++;
	}
	return (0);
}

int	display_others(t_long *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_connection,
					data->window, data->img_coll, x * WIDTH, y * HEIGHT);
			if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_connection,
					data->window, data->img_player, x * WIDTH, y * HEIGHT);
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_connection,
					data->window, data->img_exit, x * WIDTH, y * HEIGHT);
			x++;
		}
		y++;
	}
	return (0);
}
