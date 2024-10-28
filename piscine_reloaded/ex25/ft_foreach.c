/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:31:31 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/14 14:09:38 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
void	f(int a)
{
	printf("%d", a);
}

int	main(void)
{
	int	tab [100] = {0, 2, 3, 6, 6};
	int	length;

	length = 70;
	ft_foreach(tab, length, &f);
	return (0);
}*/
