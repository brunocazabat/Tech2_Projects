/*
** EPITECH PROJECT, 2019
** 04
** File description:
** 04
*/

#include "castmania.h"

void exec_operation(instruction_type_t instruction_type , void *data)
{
    instruction_t *instruct = (instruction_t*)data;
    int value = 20;

    if (instruction_type == ADD_OPERATION)
        exec_add(instruct->operation);
    else if (instruction_type == DIV_OPERATION) {
        value = 1;
        exec_div(instruct->operation);
    }
    if (instruct->output_type == VERBOSE) {
        if (value == 1)
            if (((division_t*)instruct->operation)->div_type == INTEGER)
                printf("%i\n", ((integer_op_t*)((division_t*)instruct->operation)->div_op)->res);
            else
                printf("%f\n", ((decimale_op_t*)((division_t*)instruct->operation)->div_op)->res);
            
        else
            printf("%d\n", ((addition_t*)instruct->operation)->add_op.res);
    }

}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT)
        printf("%i\n", (int)*((int*)data));
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", (float)*((float*)data));
    else
    {
        exec_operation(instruction_type, data);
    }
}