/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:52:45 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/09 11:53:15 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 8; // Initialize a counter variable i to 8
    unsigned char bit = 0; // Initialize a variable bit to 0

    while (i--) // Loop through each bit of octet
	{
        bit = (octet >> i & 1) + 48;
        write (1, &bit, 1);
	}
}


/* if you want to test your code : */
int main()
{
	unsigned char octet = 3;
	print_bits(octet);
}