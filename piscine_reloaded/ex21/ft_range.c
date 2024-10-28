/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:01:33 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/14 10:45:43 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	length;

	length = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	tab = malloc (sizeof(int) * length);
	if (!tab)
		return (NULL);
	tab[i] = 0;
	while (i < length)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
/*
int	main(void)
{
	int	i;
	int	min;
	int	max;
	int	*dest;

	i = 0;
	min = 22;
	max = 10;
	dest = ft_range(min, max);
	while (i < 12)
	{
		printf("%d", dest[i]);
		i++;
	}
	return (0);
}*/
