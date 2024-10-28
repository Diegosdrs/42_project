/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:22:45 by artberna          #+#    #+#             */
/*   Updated: 2024/06/19 17:57:25 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_atoi(const char *s)
{
	int	parity;
	int	number;

	parity = 1;
	number = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			parity = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		number *= 10;
		number += *s - 48;
		s++;
	}
	return (number * parity);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s = "   66517  723";
	printf("%d\n", ft_atoi(s));
	return (0);
}
*/