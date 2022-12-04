/*
** EPITECH PROJECT, 2019
** victim
** File description:
** victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <string>
#include <iostream>

class Victim
{
      public:
	Victim(const std::string &name);
	~Victim();
	std::string getName() const;
	virtual void getPolymorphed() const;

      protected:
	std::string _name;

      private:
};

std::ostream &operator<<(std::ostream &s, const Victim &victim);

#endif /* !VICTIM_HPP_ */
