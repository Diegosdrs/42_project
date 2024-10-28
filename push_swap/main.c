/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:44:21 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/16 09:37:06 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*li;
	t_list	*lib;

	li = NULL;
	lib = NULL;
	if (ac <= 1)
		return (0);
	if (push_swap(ac, av, &li, &lib) == 1)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	free_lst(li);
	return (0);
}
