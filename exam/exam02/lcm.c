/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:51:54 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/09 10:53:55 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int g = (a > b) ? a : b;
    
    // Check if any of the integer is null
    if (a == 0 || b == 0)
    	return (0);
    
    while (1)
    {
    	// if g is perfectly divisible by both a and b
    	// this is the lcm
        if ((g % a == 0) && (g % b == 0))
            return (g);
        g++;
    }
}

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac == 3)
	{
		unsigned int m = lcm(atoi(av[1]), atoi(av[2]));
		printf("LCM: %u\n", m);
	}
}