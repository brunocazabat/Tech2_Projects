/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first , int *second)
{
    int a = *first;
    int b = *second;

    *first = a + b;
    *second = a * b;
}
