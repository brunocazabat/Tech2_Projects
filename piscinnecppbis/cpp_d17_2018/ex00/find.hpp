/*
** EPITECH PROJECT, 2019
** 02
** File description:
** 02
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<class T>
class T::iterator do_find(T &arr, int toFind)
{
    return (std::find(arr.begin(), arr.end(), toFind));
}

#endif /* !FIND_HPP_ */
