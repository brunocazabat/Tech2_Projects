//
// EPITECH PROJECT, 2019
// ouioui
// File description:
// oui
//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int tmp_conv(std::string tmp, std::string unit)
{
    float temp;

    if (unit == "Celsius") {
        unit = "Farhenheit\0";
        temp = ((9.0 / 5.0 ) * std::stof(tmp, NULL)) + 32; 
    }
    else if (unit == "Farhenheit") {
        unit = "Celsius\0";
        temp = (5.0 / 9.0) * (std::stof(tmp, NULL) - 32);
    }
    else
        return (84);
    std::cout << std::fixed << std::right << std::setw(16) << std::setprecision(3) << temp << std::right << std::setw(16) << unit << std::endl;
}

std::string get_info()
{
    std::string input;
    std::cin >> input; 
    return (input);
}

int  main(int ac, char **av)
{
    std::string tmp;
    std::string unit;

    if (ac != 1)
        return (84);
    tmp = get_info();
    unit = get_info();
    tmp_conv(tmp, unit);

    return (0);
}