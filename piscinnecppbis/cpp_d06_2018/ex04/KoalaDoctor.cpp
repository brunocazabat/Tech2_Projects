/*
** EPITECH PROJECT, 2019
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name), _work(false)
{
    std::cout << "Dr." << _name << ": I'm Dr." << _name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    std::string patientName = koala->getName();
    std::ofstream file(patientName + ".report");
    std::string drugName[5] = { "mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf" };

    std::cout << "Dr." << _name << ": So what's goerking you Mr." << patientName << "?" << std::endl;
    koala->poke();
    if (file)
        file << drugName[random()%5];
    else
        std::cerr << "ERROR: Can't open file." << std::endl;
}

void KoalaDoctor::timeCheck()
{
    if (!_work) {
        _work = true;
        std::cout << "Dr." << _name << ": Time to get to work!" << std::endl;
    } else {
        _work = false;
        std::cout << "Dr." << _name << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}