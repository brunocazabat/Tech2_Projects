/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_
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
    std::string _message;
  };

  class ChipsetError : public NtsError
  {
  public:
    ChipsetError(std::string const& message) throw();
    ChipsetError(void) throw();
    virtual ~ChipsetError(void) throw();
  };

  class PinError : public ChipsetError
  {
  public:
    PinError(std::string const& message) throw();
    PinError(void) throw();
    virtual ~PinError(void) throw();
  };

  class LinkError : public NtsError
  {
  public:
    LinkError(std::string const& message) throw();
    LinkError(void) throw();
    virtual ~LinkError(void) throw();
  };

  class OutputLinkError : public LinkError
  {
  public:
    OutputLinkError(std::string const& message) throw();
    OutputLinkError(void) throw();
    virtual ~OutputLinkError(void) throw();
  };

  class InputError : public NtsError
  {
  public:
    InputError(std::string const& message) throw();
    InputError(void) throw();
    virtual ~InputError(void) throw();
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

#endif /* !_EXCEPTION_HPP_ */
