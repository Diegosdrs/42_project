/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:07:04 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/24 18:28:04 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_arg(int ac, char **av, t_data *data)
{
	if (check_content(av) == 1)
		return (1);
	init_struct(ac, av, data);
	if (data->nbr_philo < 1 || data->tt_die < 1 || data->tt_eat <= 0
		|| data->tt_sleep <= 0)
		return (1);
	if (ac == 6)
	{
		if (data->nbr_must_eat < 1)
			return (1);
	}
	return (0);
}

int	check_content(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_struct(int ac, char **av, t_data *data)
{
	data->nbr_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nbr_must_eat = ft_atoi(av[5]);
	else
		data->nbr_must_eat = -1;
}
