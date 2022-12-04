/*
** EPITECH PROJECT, 2019
** KoalaNurse
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int id) : _id(id), _work(false)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string koalaName;
    std::string drugName;
    std::ifstream file(filename);

    if (filename.substr(filename.find_last_of(".") + 1) != "report" || !file)
        return (drugName);
    koalaName = filename.substr(0, filename.find_last_of("."));
    std::getline(file, drugName);
    std::cout << "Nurse " << _id << ": Kreog! Mr." << koalaName << " needs a " << drugName << "!" << std::endl;
    return (drugName);
}

void KoalaNurse::timeCheck()
{
    if (!_work) {
        _work = true;
        std::cout << "Nurse " << _id << ": Time to get to work!" << std::endl;
    } else {
        _work = false;
        std::cout << "Nurse " << _id << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}