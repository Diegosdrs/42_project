/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:58:22 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/21 15:19:44 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philo)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->forks)
	{
		free(data->philo);
		return (1);
	}
	init_mutex(data);
	init_philo(data);
	if (init_threads_n_join(data) == 1)
	{
		exit_all(data->philo);
		return (1);
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].num_philo = i + 1;
		data->philo[i].nbr_eaten = 0;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].eating = 0;
		data->philo[i].start = my_time(data->philo);
		if (i == 0)
			data->philo[i].right_fork = &data->forks[data->nbr_philo - 1];
		else
			data->philo[i].right_fork = &data->forks[i - 1];
		data->philo[i].last_meal = my_time(data->philo);
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	data->stop = 0;
	data->dead_for_all = 0;
	return (0);
}

int	init_threads_n_join(t_data *data)
{
	pthread_t	checker;
	int			i;

	i = 0;
	if (pthread_create(&checker, NULL, &checker_list, data) != 0)
		return (1);
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].philo_thread, NULL, &routine,
				&data->philo[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL) != 0)
		return (1);
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
