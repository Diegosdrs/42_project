/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:28:08 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/11 11:25:35 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
void ft_putnbr(int nbr);
int is_prime(int nbr);
int ft_atoi(char *str);
int	real_prime(int nbr);


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    unsigned int nb;
    
    if (nbr < 0)
    {
        ft_putchar('-');
        nb = -nbr;
    }
    else
    	nb = nbr;
    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
}
int	real_prime(int nbr)
{
	int i = 2;
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			return (1);
		i++;
	}
	return (0);
}

int is_prime(int nbr)
{
	int i;
	int res = 0;
	
	i = 2;
	while (i <= nbr)
	{
		if (real_prime(i) == 0)
		{
			res += i;
		}
		i++;
	}
	ft_putnbr(res);
	return (0);
}

// You know how this works
int ft_atoi(char *str)
{
    int res = 0, sign = 1, i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
		if (str[i] == '-')
        {
			sign = -1;
			i++;
		}
	}
    while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    res *= sign;
    return (res);
}

int main(int ac, char **av)
{
    if (ac != 2 || ft_atoi(av[1]) <= 0)
    {
        write(1, "0\n", 2);
        return (0);
    }
    int n = ft_atoi(av[1]);
	is_prime(n);
    ft_putchar('\n');
}