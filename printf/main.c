/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:37:02 by dsindres          #+#    #+#             */
/*   Updated: 2024/09/16 11:21:36 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int a;
	char *str;
	
	a = 0;
	str = "diego";
	a = ft_printf("");
	printf("\n");
	ft_printf("%d", a);
	printf("\n\n");
	a = 0;
	a = printf("");
	printf("\n");
	printf("%d", a);
	return (0);
}
