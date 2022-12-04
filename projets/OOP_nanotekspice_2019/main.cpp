/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <iostream>
#include <string>

#include "Exception.hpp"
#include "Nanotekspice.hpp"

int	    main(int const argc, char const* const* const argv)
{
    nts::Nanotekspice *nanopute = NULL;

    if (argc < 2) {
        std::cout << "Usage: file.nts [[input=value] [...]]" << std::endl;
        return (0);
    }
    try {
        nanopute = new nts::Nanotekspice(argv[1], argc, argv);
        nanopute->shell();
        delete (nanopute);
    } 
    catch (nts::NtsError const& epute) {
        std::cout << epute.what() << std::endl;
    }

    return (0);
}
