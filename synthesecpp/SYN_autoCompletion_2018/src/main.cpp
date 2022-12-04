/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

void            print_usage()
{
    cerr << "USAGE" << endl;
    cerr << "     ./autoCompletion dictionary\n" << endl;
    cerr << "DESCRIPTION" << endl;
    cerr << "     dictionary    file containing one address per line, as knowledge base" << endl;
}

int         main (int ac, char **av)
{
    /* INITIALISATION */
    autocomp	*data = init_data();
    strinfo     *info = init_info();
    /* VARIABLES */
    ifstream    file(av[1]);
    string      line;
    /* STRUCT VECTOR */
    info->vect.push_back(autocomp());

    /* ERROR/HELP HANDLER */
    if (ac != 2 || !info || !data || !file) {
        cerr << "Invalid argument" << endl;
        return (84);
    }
    if (strcmp(av[1], info->help.c_str()) == 0) {
        print_usage();
        return (84);
    }

    /* LECTURE DU FICHIER TXT */
    if (file.is_open()) {
        while (getline(file, info->line)) {
            if (info->line.empty())
                return (84);
            if (strcmp(info->line.c_str(), "ABORT") == 0)
                return (84);
            else if (line_isvalid(info) == 84)
                cerr << info->line << endl;
            else {
                parse_line(info);
                info->goodline = info->goodline + 1;
                info->vect.push_back(autocomp());   
            }
        }
        cerr << "Unknown address" << endl;
    }

    /* DEBUT BRAIN AUTOCOMP */
    case_parser(info);

    /* EXIT */
    file.close();
    free (data);
    free (info);
    return (0);
}