/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:54:26 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/13 18:17:39 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		while (i > 1)
		{
			nb = nb * i;
			i--;
		}
	}
	return (nb);
}
/*
int	main(void)
{
	printf ("%d", ft_iterative_factorial(13));
	return (0);
}*/
