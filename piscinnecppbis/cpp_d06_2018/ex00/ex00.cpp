/*
** EPITECH PROJECT, 2019
** 00
** File description:
** 00
*/

#include <iostream>
#include <fstream>

int read_file(const char *filename)
{
    char c;
    std::ifstream file(filename);

    if (!file)
        std::cerr << "my_cat: " << filename << ": No such file or directory" << std::endl;
    while (file.get(c))
        std::cout << c;
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (84);
    }
    for (i = 1; i < ac; ++i)
        read_file(av[i]);
    return (0);
}