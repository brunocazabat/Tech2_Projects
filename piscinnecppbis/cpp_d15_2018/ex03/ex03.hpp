/*
** EPITECH PROJECT, 2019
** 03
** File description:
** 03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

template<typename T>
void foreach(T arr[], void (&func)(const T &elem), int size)
{
    for (int i = 0; i < size; i++)
        func(arr[i]);
}

#endif /* !EX03_HPP_ */
