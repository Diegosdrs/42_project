/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:27 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/08 16:24:05 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    len_base(char *str)
{
	int i;

	i= 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int find_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

char	*get_base(char *str, int base)
{
    char lcbase[] = "0123456789abcdef";
    char ucbase[] = "0123456789ABCDEF";
	char	*get_base =NULL;
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			count = 1;
		if (str[i] >= 'a' && str[i] <= 'z')
			count = 2;
		i++;
	}
	i = 0;
	if (count == 1)
	{
		while (i < base)
		{
			get_base[i] = ucbase[i];
			i++;	
		}
		return (get_base);
	}
	else if (count == 2)
	{
		while (i < base)
		{
			get_base[i] = lcbase[i];
			i++;	
		}
		return (get_base);
	}
	return (NULL);
}


int    atoi_base(char *str, int base)
{
	int i;
	int sign;
	int    res;
	char	*base2;

	i = 0;
	sign = 1;
	res = 0;
	base2 = get_base(str, base);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
	if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && find_index(str[i], base2) != 0)
	{
		res += base * res + find_index(str[i], base2) - '0';
		i++;
	}
	return (res * sign);
}

int main(void)
{
	char *str = "-3A7A79F13";
	int base = 10;
	printf("%d\n", atoi_base(str, base));
	return(0);
}
