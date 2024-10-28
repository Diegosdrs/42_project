/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:58:12 by dsindres          #+#    #+#             */
/*   Updated: 2024/07/10 15:05:43 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_tri(t_list **a, t_list **b)
{
	int	len;

	len = li_size(*a);
	if (!a || !(*a))
		return (1);
	if (in_order(a) == 0)
		return (0);
	else if (len == 2)
		sa(a);
	else if (len == 3)
		algo_for_3(a);
	else if (len == 4 || len == 5)
		algo_for_5(a, b, len);
	else
		big_algo(a, b, len);
	return (0);
}
