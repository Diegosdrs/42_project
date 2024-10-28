/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:32:14 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/13 19:01:13 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 4)
		return (2);
	else if (nb < 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d", ft_sqrt(5));
	return (0);
}*/
