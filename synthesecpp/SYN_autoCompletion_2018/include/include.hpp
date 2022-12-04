/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef INCLUDE
#define INCLUDE

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#define ASCII_SIZE 256 

using namespace std;

struct autocomp
{
    std::string         city, streetType, streetName, number;
};

struct strinfo
{
    int                 nbvirgule, posvirgule, posespace, goodline, parserinc;
    std::string         help, line, all_letter, parsed_letter;
    vector<autocomp>    vect;
};

void            print_usage();
autocomp        *init_data();
strinfo	        *init_info();
void            info_reset(strinfo *info);
int             line_isvalid(strinfo *info);
int             test_str(int j, string line);
void            parse_line(strinfo *info);
void            parse_adress(strinfo *info);
void            parse_city(strinfo *info);
void            parse_streettype(strinfo *info);
void            parse_streetname(strinfo *info);
void            case_parser(strinfo *info);
void            most_seen(strinfo *info);
void            display_letters(strinfo *info);

#endif /* !INCLUDE */