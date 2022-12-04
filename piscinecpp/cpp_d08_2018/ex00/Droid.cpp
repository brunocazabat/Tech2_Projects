/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "Droid.hpp"

size_t  Droid::getEnergy() const{
  return (this->Energy);
}

void    Droid::setEnergy(size_t Energy) {
  if (Energy > 100)
    this->Energy = 100;
  else
    this->Energy = Energy;
}

std::string Droid::getId() const {
  return (this->Id);
}
void    Droid::setId(std::string Id) {
  this->Id = Id;
}

std::string *Droid::getStatus() const {
  return (this->Status);
}

void Droid::setStatus(std::string *status) {
  this->Status = status;
}

size_t Droid::getAttack() const{
  return (this->Attack);
}

size_t Droid::getToughness() const {
  return (this->Toughness);
}

Droid::Droid(std::string serial)
{
    this->serial = serial;
    std::cout << "Droid " << this->serial << " Activated" << std::endl;
    Energy = 50;
    std::string Status = "Standing by";
}

Droid::~Droid()
{
    std::cout << "Droid " << this->serial << " Destroyed" << std::endl;
}

int main()
{
    Droid::Droid("Avenger");
    return (0);
}