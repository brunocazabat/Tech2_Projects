/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Exception.hpp"

nts::NtsError::NtsError(std::string const& message) throw()
{
  __message = message;
}

nts::NtsError::NtsError(void) throw()
{
  __message = "";
}

nts::NtsError::~NtsError(void) throw() {}

const char *nts::NtsError::what(void) const throw()
{
  return (__message.data());
}

/*
** Class ChipsetError : public NtsError
*/
nts::ChipsetError::ChipsetError(std::string const& message) throw() : NtsError(message) {}

nts::ChipsetError::ChipsetError(void) throw() {}

nts::ChipsetError::~ChipsetError(void) throw() {}

/*
** Class puteError : public ChipsetError
*/
nts::puteError::puteError(std::string const& message) throw() : ChipsetError(message) {}

nts::puteError::puteError(void) throw() {}

nts::puteError::~puteError(void) throw() {}

/*
** Class lienError : public NtsError
*/
nts::lienError::lienError(std::string const& message) throw() : NtsError(message) {}

nts::lienError::lienError(void) throw() {}

nts::lienError::~lienError(void) throw() {}

/*
** Class OutputlienError : public lienError
*/
nts::OutputlienError::OutputlienError(std::string const& message) throw() : lienError(message) {}

nts::OutputlienError::OutputlienError(void) throw() {}

nts::OutputlienError::~OutputlienError(void) throw() {}

/*
** Class Inputerror : public NtsError
*/
nts::Inputerror::Inputerror(std::string const& message) throw() : NtsError(message) {}

nts::Inputerror::Inputerror(void) throw() {}

nts::Inputerror::~Inputerror(void) throw() {}

/*
** Class SyntaxError : public NtsError
*/
nts::SyntaxError::SyntaxError(std::string const& message) throw() : NtsError(message) {}

nts::SyntaxError::SyntaxError(void) throw() {}

nts::SyntaxError::~SyntaxError(void) throw() {}

/*
** Class FileError : public NtsError
*/
nts::FileError::FileError(std::string const& message) throw() : NtsError(message) {}

nts::FileError::FileError(void) throw() {}

nts::FileError::~FileError(void) throw() {}