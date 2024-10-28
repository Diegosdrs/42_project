/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:34:38 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/06 15:46:26 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int keysym, t_long *data)
{
	static int	count_input;
	static int	count_input_copy;
	t_long		player;

	find_p(data->map, &player);
	if (keysym == XK_Escape)
		escape(data);
	else if (keysym == XK_w)
		count_input += move_up(data, &player);
	else if (keysym == XK_a)
		count_input += move_left(data, &player);
	else if (keysym == XK_s)
		count_input += move_down(data, &player);
	else if (keysym == XK_d)
		count_input += move_right(data, &player);
	else
		return (0);
	display_image(data);
	if (count_input_copy != count_input)
		ft_printf("%d\n", count_input);
	count_input_copy = count_input;
	if (data->c == 0 && data->e == 0)
		you_win(data, count_input);
	return (0);
}

int	move_up(t_long *data, t_long *player)
{
	if (data->map[player->y - 1][player->x] != '1')
	{
		if (data->map[player->y - 1][player->x] == 'C')
			data->c--;
		if (data->map[player->y - 1][player->x] == 'E' && data->c > 0)
		{
			ft_printf("Il reste des items a collecter !\n");
			if (data->map[player->y - 2][player->x] != '1')
			{
				if (data->map[player->y - 2][player->x] == 'C')
					data->c--;
				data->map[player->y - 2][player->x] = 'P';
				data->map[player->y][player->x] = '0';
				return (1);
			}
			return (0);
		}
		if (data->map[player->y - 1][player->x] == 'E' && data->c == 0)
			data->e = 0;
		data->map[player->y - 1][player->x] = 'P';
		data->map[player->y][player->x] = '0';
		return (1);
	}
	return (0);
}

int	move_left(t_long *data, t_long *player)
{
	if (data->map[player->y][player->x - 1] != '1')
	{
		if (data->map[player->y][player->x - 1] == 'C')
			data->c--;
		if (data->map[player->y][player->x - 1] == 'E' && data->c > 0)
		{
			ft_printf("Il reste des items a collecter !\n");
			if (data->map[player->y][player->x - 2] != '1')
			{
				if (data->map[player->y][player->x - 2] == 'C')
					data->c--;
				data->map[player->y][player->x - 2] = 'P';
				data->map[player->y][player->x] = '0';
				return (1);
			}
			return (0);
		}
		if (data->map[player->y][player->x - 1] == 'E' && data->c == 0)
			data->e = 0;
		data->map[player->y][player->x - 1] = 'P';
		data->map[player->y][player->x] = '0';
		return (1);
	}
	return (0);
}

int	move_down(t_long *data, t_long *player)
{
	if (data->map[player->y + 1][player->x] != '1')
	{
		if (data->map[player->y + 1][player->x] == 'C')
			data->c--;
		if (data->map[player->y + 1][player->x] == 'E' && data->c > 0)
		{
			ft_printf("Il reste des items a collecter !\n");
			if (data->map[player->y + 2][player->x] != '1')
			{
				if (data->map[player->y + 2][player->x] == 'C')
					data->c--;
				data->map[player->y + 2][player->x] = 'P';
				data->map[player->y][player->x] = '0';
				return (1);
			}
			return (0);
		}
		if (data->map[player->y + 1][player->x] == 'E' && data->c == 0)
			data->e = 0;
		data->map[player->y + 1][player->x] = 'P';
		data->map[player->y][player->x] = '0';
		return (1);
	}
	return (0);
}

int	move_right(t_long *data, t_long *player)
{
	if (data->map[player->y][player->x + 1] != '1')
	{
		if (data->map[player->y][player->x + 1] == 'C')
			data->c--;
		if (data->map[player->y][player->x + 1] == 'E' && data->c > 0)
		{
			ft_printf("Il reste des items a collecter !\n");
			if (data->map[player->y][player->x + 2] != '1')
			{
				if (data->map[player->y][player->x + 2] == 'C')
					data->c--;
				data->map[player->y][player->x + 2] = 'P';
				data->map[player->y][player->x] = '0';
				return (1);
			}
			return (0);
		}
		if (data->map[player->y][player->x + 1] == 'E' && data->c == 0)
			data->e = 0;
		data->map[player->y][player->x + 1] = 'P';
		data->map[player->y][player->x] = '0';
		return (1);
	}
	return (0);
}
