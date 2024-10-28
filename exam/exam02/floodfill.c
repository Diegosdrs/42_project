/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:41:47 by dsindres          #+#    #+#             */
/*   Updated: 2024/08/09 11:42:33 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Recursive function to flood fill an area of a 2D character array
void fill(char **tab, t_point size, char target, int row, int col)
{
    // Check if current row and column values are out of bounds
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;
    
    // Check if current cell has already been filled or does not match the target character
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return;

    // Mark current cell as filled
    tab[row][col] = 'F';

    // Recursively fill neighboring cells
    fill(tab, size, target, row -1, col); // fill cell above
    fill(tab, size, target, row +1, col); // fill cell below
    fill(tab, size, target, row, col - 1); // fill cell to the left
    fill(tab, size, target, row, col + 1); // fill cell to the right
}

// Function to initiate flood fill from a specified point
void flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x]; // Get the character to fill around
    fill(tab, size, target, begin.y, begin.x); // Start the flood fill from the specified point
}
