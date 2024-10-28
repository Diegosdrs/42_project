/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_prime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:57:59 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/19 13:58:10 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void print_prime_factors(int number)
{
    int divisor = 2;

    if (number == 1)
    {
        printf("1");
        return;
    }

    while (number > 1)
    {
        while (number % divisor == 0)
        {
            printf("%d", divisor);
            number /= divisor;
            if (number > 1)
            {
                printf("*");
            }
        }
        divisor++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int number = atoi(argv[1]);
        print_prime_factors(number);
    }
    printf("\n");
    return (0);
}
