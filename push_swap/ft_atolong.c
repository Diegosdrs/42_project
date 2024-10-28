/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:17:42 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/11 14:15:15 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atolong(const char *str)
{
	long	i;
	long	sign;
	long	result;
	long	overflow;

	i = 0;
	sign = 1;
	result = 0;
	overflow = 100000000000000000;
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
		if (result > INT_MAX || result < INT_MIN)
			return (overflow);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}
