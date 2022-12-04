/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include <exception>

namespace nts
{
  class NtsError : public std::exception
  {
  public:
    NtsError(std::string const& e) throw();
    NtsError(void) throw();
    virtual ~NtsError(void) throw();

    virtual const char *what(void) const throw();
  private:
    std::string __message;
  };

  class ChipsetError : public NtsError
  {
  public:
    ChipsetError(std::string const& message) throw();
    ChipsetError(void) throw();
    virtual ~ChipsetError(void) throw();
  };

  class puteError : public ChipsetError
  {
  public:
    puteError(std::string const& message) throw();
    puteError(void) throw();
    virtual ~puteError(void) throw();
  };

  class lienError : public NtsError
  {
  public:
    lienError(std::string const& message) throw();
    lienError(void) throw();
    virtual ~lienError(void) throw();
  };

  class OutputlienError : public lienError
  {
  public:
    OutputlienError(std::string const& message) throw();
    OutputlienError(void) throw();
    virtual ~OutputlienError(void) throw();
  };

  class Inputerror : public NtsError
  {
  public:
    Inputerror(std::string const& message) throw();
    Inputerror(void) throw();
    virtual ~Inputerror(void) throw();
  };

  class SyntaxError : public NtsError
  {
  public:
    SyntaxError(std::string const& message) throw();
    SyntaxError(void) throw();
    virtual ~SyntaxError(void) throw();
  };

  class FileError : public NtsError
  {
  public:
    FileError(std::string const& message) throw();
    FileError(void) throw();
    virtual ~FileError(void) throw();
  };
}