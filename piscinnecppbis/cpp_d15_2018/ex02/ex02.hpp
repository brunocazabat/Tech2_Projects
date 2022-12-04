/*
** EPITECH PROJECT, 2019
** 02
** File description:
** 02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    return ((a <= b) ? a : b);
}

template<typename T>
T templateMin(T arr[], int size)
{
    T _min = arr[0];

    for(int i = 1; i < size; i++)
        _min = ::min(_min, arr[i]);
    return (_min);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    return ((a <= b) ? a : b);
}

int nonTemplateMin(int arr[], int size)
{
    int _min = arr[0];

    for(int i = 1; i < size; i++)
        _min = ::min(_min, arr[i]);
    return (_min);
}

#endif /* !EX02_HPP_ */
