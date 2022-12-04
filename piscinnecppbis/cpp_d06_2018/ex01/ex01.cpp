/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** ex01
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 

int convert_temp(void)
{
    std::string temp;
    std::string scale;
    float ret = 0.0;

    std::cin >> temp;
    std::cin >> scale;
    if (scale == "Celsius") {
        ret = 9.0 / 5.0 * (stof(temp, NULL)) + 32;
        std::cout << std::right << std::fixed << std::setw(16) << std::setprecision(3) << ret << std::right << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (scale == "Fahrenheit") {
        ret = 5.0 / 9.0 * (stof(temp, NULL) - 32);
        std::cout << std::right << std::fixed << std::setw(16) << std::setprecision(3) << ret << std::right << std::setw(16) << "Celsius" << std::endl;
    }
    return (0);
}

int main(void)
{
    return (convert_temp());
}