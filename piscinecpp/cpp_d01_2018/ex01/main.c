/*
** EPITECH PROJECT, 2019
** oui
** File description:
** oui
*/
#include "menger.h"

int     my_getnbr(char const *str)
{
        int     i = 0;
        int     nb = 0;
        int     j = 0;

        while (str[i] != '\0') {
                while (str[i] == '-') {
                        i++;
                        j++;
                }
                nb = (nb * 10) + (str[i] - '0');
                i++;
        }
        if (j % 2 == 1 && j > 0)
                nb = nb * -1;
        return (nb);
}

int	main(int ac, char **av)
{
	int size = 0;
	int level = 0;
	
	if (ac != 3)
		return (84);
	size = my_getnbr(av[1]);
	level = my_getnbr(av[2]);
	
	
	return (0);
}
