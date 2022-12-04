/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"


void        parse_line(strinfo *info)
{
    parse_city(info);
    parse_adress(info);
    parse_streettype(info);
    parse_streetname(info);
}

void        parse_streetname(strinfo *info)
{
    string token = "oui";
    
    if (token != "j'en ai marre") {
        token = info->line;  
        info->vect[info->goodline].streetName = token;
    }
}

void        parse_streettype(strinfo *info)
{
    string token = "oui";
    
    if (token != " ") {
        token = info->line.substr(0, info->line.find_first_of(" "));
        info->line = info->line.substr(info->line.find_first_of(" ") + 1);
        info->vect[info->goodline].streetType = token;
    }
}

void        parse_adress(strinfo *info)
{
    string token = "oui";
    
    if (token != " ") {
        token = info->line.substr(0, info->line.find_first_of(" "));
        info->line = info->line.substr(info->line.find_first_of(" ") + 1);
        info->vect[info->goodline].number = token;
    }
}

void        parse_city(strinfo *info)
{
    string token    = "oui";
    string letter   = "oui";
    
    if (token != ",") {
        token = info->line.substr(0, info->line.find_first_of(","));
        info->line = info->line.substr(info->line.find_first_of(",") + 2);
        info->vect[info->goodline].city = token;
        info->all_letter.push_back(token[0]);
    }
}