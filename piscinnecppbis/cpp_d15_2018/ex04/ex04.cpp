/*
** EPITECH PROJECT, 2019
** 04
** File description:
** 04
*/

#include "ex04.hpp"

template<>
Tester<int>::Tester()
{
}

template<>
Tester<int>::~Tester()
{
}

template<>
bool Tester<int>::equal(const int &a, const int &b)
{
    return ((a == b) ? true : false);
}

template<>
bool equal(const int &a, const int &b)
{
    return ((a == b) ? true : false);
}

template<>
Tester<float>::Tester()
{
}

template<>
Tester<float>::~Tester()
{
}

template<>
bool Tester<float>::equal(const float &a, const float &b)
{
    return ((a == b) ? true : false);
}

template<>
bool equal(const float &a, const float &b)
{
    return ((a == b) ? true : false);
}

template<>
Tester<double>::Tester()
{
}

template<>
Tester<double>::~Tester()
{
}

template<>
bool Tester<double>::equal(const double &a, const double &b)
{
    return ((a == b) ? true : false);
}

template<>
bool equal(const double &a, const double &b)
{
    return ((a == b) ? true : false);
}

template<>
Tester<std::string>::Tester()
{
}

template<>
Tester<std::string>::~Tester()
{
}

template<>
bool Tester<std::string>::equal(const std::string &a, const std::string &b)
{
    return ((a == b) ? true : false);
}

template<>
bool equal(const std::string &a, const std::string &b)
{
    return ((a == b) ? true : false);
}