/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:08:36 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/09 11:08:44 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    // Continue jusqu'à ce que b soit nul
    while (b != 0)
    {
        // Calculer le reste de la division de a par b
        int temp = b;
        b = a % b;
        a = temp;
    }
    // Lorsque b est nul, a est le PGCD
    return a;
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int number1 = atoi(av[1]);
        int number2 = atoi(av[2]);

        if (number1 > 0 && number2 > 0)
        {
            // Appelle la fonction gcd pour trouver le PGCD
            int result = gcd(number1, number2);
            printf("%d", result);
        }
    }
    printf("\n");
}
