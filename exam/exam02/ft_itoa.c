/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:02:49 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/19 14:19:45 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr) 
{
	int n;
	int len;
	char *result;
	
	n = nbr;
	len = 0;
	if(nbr == -2147483648)
		return("-2147483648\0");
	if (nbr <= 0)
		len++;
	while (n != 0) 
	{
		n /= 10;
		len++;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result) 
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return(result);
	}
	if (nbr < 0) 
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0) 
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int main(void)
{
	printf("%s\n", ft_itoa(-484555462));
	return(0);
}