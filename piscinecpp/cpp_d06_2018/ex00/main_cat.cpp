//
// EPITECH PROJECT, 2019
// ouioui
// File description:
// oui
//
#include <iostream>
#include <string>
#include <fstream>

void my_counter(char *av)
{
    char c;

    std::ifstream file(av, std::ifstream::in);

    if (file)
        while(file.get(c)) {
            std::cout << c;
	}
    else
	    std::cerr << "my_cat: " << av << ": No such file or directory" << std::endl; 
    file.close();
}

int  main(int ac, char **av)
{
    int i = 1;

    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
	return (84);
    }
    while (av[i]) {		
	my_counter(av[i]);
	i = i + 1;
    }
    return (0);
}
