/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:29:32 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/07 10:21:33 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_controler(t_long *data)
{
	if (data->y >= 16 || data->x >= 30)
	{
		ft_printf("Map trop grande\n");
		free_double(data->map);
		exit(EXIT_FAILURE);
	}
	data->mlx_connection = mlx_init();
	if (data->mlx_connection == NULL)
	{
		free_double(data->map);
		exit(EXIT_FAILURE);
	}
	init_ptr_img(data);
	if (init_image(data) == 1)
		free_all(data);
	display_window(data);
	display_image(data);
	mlx_key_hook(data->window, key_input, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_loop(data->mlx_connection);
	return (0);
}

int	display_window(t_long *data)
{
	data->window = mlx_new_window(data->mlx_connection, data->x * WIDTH,
			data->y * HEIGHT, "APOCALYPSE : The Wolf Zombie !");
	if (data->window == NULL)
		free_all(data);
	return (0);
}

int	init_image(t_long *data)
{
	int	img_width;
	int	img_height;

	data->img_back = mlx_xpm_file_to_image(data->mlx_connection,
			data->path_back, &img_width, &img_height);
	if (data->img_back == NULL)
		return (1);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_connection,
			data->path_wall, &img_width, &img_height);
	if (data->img_wall == NULL)
		return (1);
	data->img_coll = mlx_xpm_file_to_image(data->mlx_connection,
			data->path_coll, &img_width, &img_height);
	if (data->img_coll == NULL)
		return (1);
	data->img_player = mlx_xpm_file_to_image(data->mlx_connection,
			data->path_player, &img_width, &img_height);
	if (data->img_player == NULL)
		return (1);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_connection,
			data->path_exit, &img_width, &img_height);
	if (data->img_exit == NULL)
		return (1);
	return (0);
}

void	init_ptr_img(t_long *data)
{
	data->path_back = "./img/back.xpm";
	data->path_wall = "./img/wall.xpm";
	data->path_coll = "./img/coll.xpm";
	data->path_exit = "./img/exit.xpm";
	data->path_player = "./img/player.xpm";
	data->img_back = NULL;
	data->img_wall = NULL;
	data->img_coll = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->window = NULL;
}
