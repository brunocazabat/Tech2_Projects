/*
** EPITECH PROJECT, 2019
** 04
** File description:
** 04
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    int res = 0;
    
    if (b == 0)
        return (0);
        
    res = a / b;
    return (res);
}

float decimale_div(int a, int b)
{
    float res = 0.0;

    if (b == 0)
        return (0);
    
    res = (float)a / (float)b;
    return (res);
}

void exec_div(division_t *operation)
{
    integer_op_t*   int_op;
    decimale_op_t*  dec_op;

    if (operation->div_type == INTEGER) {
        int_op = (integer_op_t*)operation->div_op;
        int_op->res = integer_div(int_op->a, int_op->b);
    }
    else if (operation->div_type == DECIMALE) {
        dec_op = (decimale_op_t*)operation->div_op;
        dec_op->res = integer_div(dec_op->a, dec_op->b);
    }
}