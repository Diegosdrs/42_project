/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:51:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/30 11:55:29 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->data->nbr_philo == 1)
	{
		just_wait(philo->data->tt_die, philo);
		print_action("is dead", philo, philo->num_philo);
		return (NULL);
	}
	if (philo->num_philo % 2 == 0)
		just_wait(100, philo);
	while (someone_dead(philo) != 1)
	{
		just_eat(philo);
		just_dream(philo);
		just_think(philo);
	}
	return (ptr);
}

void	just_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action ("has taken a fork", philo, philo->num_philo);
	pthread_mutex_lock(philo->right_fork);
	print_action ("has taken a fork", philo, philo->num_philo);
	print_action ("is eating", philo, philo->num_philo);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->nbr_eaten++;
	philo->last_meal = my_time(philo);
	pthread_mutex_unlock(&philo->data->eat_mutex);
	just_wait(philo->data->tt_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	just_think(t_philo *philo)
{
	print_action("is thinking", philo, philo->num_philo);
}

void	just_dream(t_philo *philo)
{
	print_action("is sleeping", philo, philo->num_philo);
	just_wait(philo->data->tt_sleep, philo);
}
