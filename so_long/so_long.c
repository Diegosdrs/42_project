/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:36:56 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/07 11:05:54 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_long	data;

	if (ac != 2)
		return (0);
	data.map = check_file(av[1], &data);
	if (data.map == NULL)
		return (0);
	game_controler(&data);
	return (0);
}
