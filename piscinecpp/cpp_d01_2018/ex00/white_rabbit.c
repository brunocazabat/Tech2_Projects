/*
** EPITECH PROJECT, 2019
** white_rabbit.c
** File description:
** C sounds like shit for me/no mains allowed
*/
#include <stdlib.h>
#include <stdio.h>

int	follow_the_white_rabbit(void)
{
	int i = 0;
	static int compteur = 0;

	i = (random() % 37) + 1;
	if (i == 37 || i == 1 || compteur > 396) {
		printf("RABBIT!!!\n");
		compteur = compteur + i;
		return (compteur);
	}
	else if (i == 13 || i > 33)
		printf("right\n");
	else if ((i < 7 && i > 3) || i == 28 || (i < 22 && i > 16))
		printf("left\n");
	else if  (i == 10 || i == 15 || i == 23)
		printf("forward\n");
	else if ((i % 8) == 0 || i == 26)
		printf("backward\n");
	compteur = compteur + i;
	follow_the_white_rabbit();
	return (compteur);
}
