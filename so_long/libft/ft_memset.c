/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:45:56 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/22 11:18:10 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
    size_t size = sizeof( int ) * 5;
    int length;
	int array [5] = { 54, 85, 20, 63, 21};


    
    for( length=0; length<5; length++) 
	{
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    
    ft_memset( array, 0, size );

    
    for( length=0; length<5; length++) 
	{
        printf( "%d ", array[ length ] );
    }

    printf( "\n" );
    
    return 0;
}
*/
