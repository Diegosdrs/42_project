/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:12:20 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/23 09:59:57 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (i == n)
		return (0);
	while (s1[i] && i < (n - 1) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main() 
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, aorle!";

    size_t n = 0;
    int result = ft_strncmp(str1, str2, n);

    if (result == 0) {
        printf("The first %zu characters of str1 and str2 are equal.\n", n);
    } else if (result < 0) {
        printf("str1 is less than str2 in the first %zu characters.\n", n);
    } else {
        printf("str1 is greater than str2 in the first %zu characters.\n", n);
    }

    return 0;
}*/
