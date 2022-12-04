/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"


int         test_str(strinfo *info)
{
    if (info->nbvirgule != 1)
        return (84);
    
    if (info->posvirgule == 0)
        return (84);

    if (info->line[info->posvirgule + 1] != ' ')
        return (84);

    if (isalpha(info->line[0]) == 0)
        return (84);

    if (isalpha(info->line[info->posvirgule - 1]) == 0)
        return (84);

    if (static_cast<unsigned char>(isdigit(info->line[info->posvirgule+2])) == 0)
        return (84);

    return (0);
}

void        info_reset(strinfo *info)
{
    info->posvirgule = 0;
    info->posespace = 0;
    info->nbvirgule = 0;
    info->parserinc = 0;
    info->parsed_letter.assign("");
}

int         line_isvalid(strinfo *info)
{
    info_reset(info);
    int i = 0;

    if (info->line[i] == '\0' || info->line[i] == '\n')
        return (84);

    while (info->line[i] != ',') {
        i = i + 1;
        if (info->line[i] == '\0')
            return (84);
    }

    info->nbvirgule = info->nbvirgule + 1;
    info->posvirgule = i;

    i = i + 1;

    while (info->line[i] != '\0') {
        if (info->line[i] == ',')
            info->nbvirgule = info->nbvirgule + 1;
        i = i + 1;
    }

    if (test_str(info) == 84)
        return (84);
    
    return (0);
}