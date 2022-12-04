/*
** EPITECH PROJECT, 2019
** 01
** File description:
** 01
*/

#include "menger.h"

int is_digit(char *str)
{
	while (*str)
		if (isdigit(*str++) == 0)
			return (0);
	return (1);
}

int menger(int size)
{
	int edge = 0;
	int x = 0;
	int y = 0;

	if (size / 3 == 0)
		return (0);
	edge = size / 3;
	x = edge;
	y = edge;

	while (x < size * 3)
	{
		while (y < size * 3)
		{
			if (!((y > size && y < size * 2) && (x > size && x < size * 2)))
			{
				printf("%03d %03d %03d\n", edge, x, y);
			}
			y += size;
		}
		y = edge;
		x += size;
	}
	return (0);
}