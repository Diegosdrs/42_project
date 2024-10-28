/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:18:37 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/19 15:30:25 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int start;
	int end;
	int i;
	int flag;
	char *str;

	str = av[1];
	i = 0;
	if(ac == 2)
	{
		while(str[i] != '\0')
			i++;
		while(i >= 0)
		{
			while( str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
				i--;
			end = i;
			while(str[i] && str[i] != ' ' && str[i] != '\t')
				i--;
			start = i + 1;
			flag = start;
			while(start <= end)
			{
				write (1, &str[start],1);
				start++;
			}
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
