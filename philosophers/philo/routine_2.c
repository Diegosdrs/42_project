/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:28:04 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/21 15:20:03 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *str, t_philo *philo, int num)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = my_time(philo) - philo->start;
	if (!someone_dead(philo))
		printf("%zu %d %s\n", time, num, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return ;
}

size_t	my_time(t_philo *philo)
{
	struct timeval	tv;
	size_t			result;

	if (gettimeofday(&tv, NULL) == -1)
		exit_all(philo);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (result);
}

size_t	just_wait(size_t time_in_ms, t_philo *philo)
{
	size_t	start;

	start = my_time(philo);
	while (time_in_ms > (my_time(philo) - start))
		usleep(500);
	return (0);
}

int	someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->dead_for_all == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}
