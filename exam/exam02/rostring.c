/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:33:20 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/19 15:47:06 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_word(char *start, char *end)
{
    while (start < end)
    {
		write(1, start, 1);
		start++;
	}
}

int main(int argc, char **argv)
{
    char *str;
    char *first_word_start;
    char *first_word_end;
	int i;

	i = 0;
    if (argc > 1)
    {
        str = argv[1];
        while (str[i] == ' ' || str[i] == '\t') 
			i++;
        first_word_start = str + i;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
        first_word_end = str + i;
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] != '\0');
		{
            while (str[i])
            {
                if (str[i] == ' ' || str[i] == '\t')
                {
                    while (str[i] == ' ' || str[i] == '\t')
                        i++;
                    if (str[i])
                        write(1, " ", 1);
                } 
                else 
                {
                    write(1, &str[i], 1);
                    i++;
                }
            }
            write(1, " ", 1);
        }
        write_word(first_word_start, first_word_end);
    }
    write(1, "\n", 1);
    return 0;
}
