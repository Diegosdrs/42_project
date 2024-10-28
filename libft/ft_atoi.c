/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:14 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/20 11:42:03 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}
/*
int	main(void)
{
	char	*str = "--2569";
	printf("%d\n", ft_atoi(str));


	char	*str2 = "   -42";
	printf("%d\n", ft_atoi(str2)); // Doit afficher -42

	char	*str3 = "4193 with words";
	printf("%d\n", ft_atoi(str3)); // Doit afficher 4193

	char	*str4 = "words and 987";
	printf("%d\n", ft_atoi(str4)); // Doit afficher 0

	char	*str5 = "-91283472332";
	printf("%d\n", ft_atoi(str5)); // Doit afficher un nombre négatif

	return (0);
}*/
