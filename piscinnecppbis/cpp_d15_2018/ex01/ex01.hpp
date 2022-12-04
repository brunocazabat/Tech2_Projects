/*
** EPITECH PROJECT, 2019
** 01
** File description:
** 01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return (0);
    else if (a > b)
        return (1);
    else
        return (-1);
}

#endif /* !EX01_HPP_ */
