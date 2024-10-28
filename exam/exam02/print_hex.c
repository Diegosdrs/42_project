/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:18:55 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/11 11:57:19 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Simple atoi to convert the parameter to unsigned int
// You might need to manage negative numbers and all of
// that, it isn't specified in the subject if they could
// be sent to your program or not
unsigned int ft_atoi(char *str)
{
    unsigned int res = 0, i = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res *= 10;
		res += str[i] - '0';
		i++;
    }
    return (res);
}

void put_hex(int nbr)
{
    char *base = "0123456789abcdef";

    if (nbr >= 16)
        put_hex(nbr / 16);
    // choosing the char corresponding to the number we want
    // and writing it to the screen
    nbr = base[nbr % 16];
    write(1, &nbr, 1);
}

int main(int ac, char **av)
{
    // if there is an argument, send it directly to the
    // put_hex function via ft_atoi
    if (ac == 2)
        put_hex(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}