/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:10:55 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/21 15:18:20 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res);
}

void	exit_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_destroy(&philo->data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print_mutex);
	pthread_mutex_destroy(&philo->data->dead_mutex);
	pthread_mutex_destroy(&philo->data->eat_mutex);
	free(philo->data->forks);
	free(philo);
}
