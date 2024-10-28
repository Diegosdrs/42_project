/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:16:53 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/09 11:02:06 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av, t_list **li, t_list **lib)
{
	char	**str;
	int		i;

	i = 0;
	str = manage_imput(ac, av);
	if (manage_list(str, li) == 1)
		return (1);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (algo_tri(li, lib) == 1)
		return (1);
	return (0);
}

char	**manage_imput(int ac, char **av)
{
	char	*str;
	char	**str2;
	int		i;

	i = 0;
	str = parsing(ac, av);
	str2 = ft_split(str, ' ');
	i = 0;
	if ((valid_imput(str2)) == 1)
	{
		write (2, "Error\n", 6);
		free(str);
		while (str2[i])
		{
			free(str2[i]);
			i++;
		}
		free(str2);
		exit(EXIT_FAILURE);
	}
	free(str);
	return (str2);
}

int	manage_list(char **str, t_list **li)
{
	int	i;

	i = 0;
	if (create_list(str, li) == 1)
	{
		free_lst(*li);
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (1);
	}
	return (0);
}
