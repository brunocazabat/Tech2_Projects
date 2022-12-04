/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"


int             letter_count(strinfo *info, char tmp)
{
    size_t n = count(info->all_letter.begin(), info->all_letter.end(), tmp);
    
    return (n);
}

void            most_seen(strinfo *info)
{
    int i       = 0;
    int oui     = 0;
    string tmp  ;
    char j      ;

    info_reset(info);
    
    while (info->all_letter.size() != 0) {
        j = info->all_letter[i];
        oui = letter_count(info, j);
        info->parsed_letter  += j;
        tmp = to_string(oui);
        info->parsed_letter += tmp;
        info->all_letter.erase(remove(info->all_letter.begin(), info->all_letter.end(), j), info->all_letter.end());
    }
}

void            line_write(int occ, char j)
{
    char tmp;

    if (isupper(j))
        tmp = tolower(j);
    if (occ == 1)
        cout << "{" << tmp << "}" << endl;
    else
        cout << "{" << tmp << "} ";
}

void            display_letters(strinfo *info)
{
    int i           = 0;
    int length      = info->parsed_letter.length();
    int occ         = length / 2;
    int save        = 0;
    char j          ;
    char oui        ;

    while(length != 0) {
        while (info->parsed_letter[i + 1] != '\0') {
            if ((info->parsed_letter[i + 1] - 48) >= save) {
                save    = info->parsed_letter[i + 1] - 48;
                j       = info->parsed_letter[i];
            }
            i += 2;
        }

        oui = save + 48;
        info->parsed_letter.erase(remove(info->parsed_letter.begin(), info->parsed_letter.end(), oui), info->parsed_letter.end());
        info->parsed_letter.erase(remove(info->parsed_letter.begin(), info->parsed_letter.end(), j), info->parsed_letter.end());
        cout << info->parsed_letter << endl;
        
        length = info->parsed_letter.length();

        if (occ != 0) {
            line_write(occ, j);
            occ = occ - 1;
            save = 0;
            i = 0;
        }
        else
            break;
    }
}

void            case_parser(strinfo *info)
{
    if (info->goodline == 1)
        cout << "=> " << info->vect[info->goodline-1].city << ", " << info->vect[info->goodline-1].number << " " 
            << info->vect[info->goodline-1].streetType << " " << info->vect[info->goodline-1].streetName << endl;
    else {
        most_seen(info);
        display_letters(info);
    }
}