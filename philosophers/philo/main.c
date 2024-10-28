/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:12:29 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/30 11:00:07 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 5 && ac != 6)
	{
		printf("Mauvais nombre d'arguments\n");
		return (1);
	}
	if (verif_arg(ac, av, &data) == 1)
	{
		printf("Arguments incorrects\n");
		return (1);
	}
	if (philosophers (&data) == 1)
	{
		printf("Erreur de creation des threads\n");
		return (1);
	}
	exit_all(data.philo);
	return (0);
}
