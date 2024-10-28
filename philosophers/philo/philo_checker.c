/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:10:14 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/30 11:55:15 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker_list(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		if (philo_dead(data) == 1 || all_have_eaten(data) == 1)
			break ;
	}
	return (ptr);
}

int	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->eat_mutex);
	if ((my_time(data->philo) - data->philo->last_meal) >= (size_t)data->tt_die)
	{
		pthread_mutex_unlock(&data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->eat_mutex);
	return (0);
}

int	philo_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (is_dead(data))
		{
			print_action("died", &data->philo[i], data->philo[i].num_philo);
			pthread_mutex_lock(&data->dead_mutex);
			data->dead_for_all = 1;
			pthread_mutex_unlock(&data->dead_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_have_eaten(t_data *data)
{
	int	i;
	int	eat_count;

	eat_count = 0;
	i = 0;
	if (data->nbr_must_eat == -1)
		return (0);
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&data->eat_mutex);
		if (data->philo[i].nbr_eaten >= data->nbr_must_eat)
			eat_count++;
		pthread_mutex_unlock(&data->eat_mutex);
		i++;
	}
	if (data->nbr_philo == eat_count)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->dead_for_all = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	return (0);
}
