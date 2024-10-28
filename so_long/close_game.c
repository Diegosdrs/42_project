/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:33:31 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/07 10:23:07 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_long *data)
{
	free_all(data);
	return (1);
}

void	escape(t_long *data)
{
	ft_printf("THE END\n\n");
	free_all(data);
}

void	you_win(t_long *data, int count_input)
{
	ft_printf("YOU  WIN in %d coups !\n\n", count_input);
	free_double(data->map);
	if (data->img_wall != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_wall);
	if (data->img_back != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_back);
	if (data->img_coll != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_coll);
	if (data->img_player != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_player);
	if (data->img_exit != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_exit);
	if (data->window != NULL)
		mlx_destroy_window(data->mlx_connection, data->window);
	mlx_destroy_display(data->mlx_connection);
	free(data->mlx_connection);
	exit(EXIT_SUCCESS);
}

void	free_all(t_long *data)
{
	free_double(data->map);
	if (data->img_wall != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_wall);
	if (data->img_back != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_back);
	if (data->img_coll != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_coll);
	if (data->img_player != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_player);
	if (data->img_exit != NULL)
		mlx_destroy_image(data->mlx_connection, data->img_exit);
	if (data->window != NULL)
		mlx_destroy_window(data->mlx_connection, data->window);
	mlx_destroy_display(data->mlx_connection);
	free(data->mlx_connection);
	exit(EXIT_FAILURE);
}
