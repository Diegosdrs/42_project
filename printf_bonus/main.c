/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:34:13 by dsindres          #+#    #+#             */
/*   Updated: 2024/05/29 17:41:20 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	x;

	x = 'a';
	ft_printf("je suis un gros con [%-5c], et j'aime la vie [%s]", x, "bulle");
	return (0);
}