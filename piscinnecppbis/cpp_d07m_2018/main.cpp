/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Federation.hpp"
#include "Borg.hpp"

int main()
{
    Federation::Starfleet ::Ship UssKreog(289, 132, "Kreog", 6);
    Federation::Ship Independant(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Independant.setupCore(&core2);
    Independant.checkCore();
    QR.setStability(false);
    QR2.setStability(false);
    UssKreog.checkCore();
    Independant.checkCore();

    Federation::Starfleet ::Captain James("James T. Kirk");
    Federation::Starfleet ::Ensign Ensign("Pavel  Chekov");
    UssKreog.promote(&James);
    Borg::Ship Cube;
    Cube.setupCore(&core2);
    Cube.checkCore();
    return 0;
}