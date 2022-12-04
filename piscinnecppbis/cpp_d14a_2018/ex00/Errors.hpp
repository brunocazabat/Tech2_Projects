
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");
        ~NasaError() {};
        std::string const &getComponent() const;
        const char *what() const noexcept override {
            return (_message.c_str());
        };
    protected:
        std::string _component;

    private:
        std::string _message;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
        ~MissionCriticalError() {};
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
        ~LifeCriticalError() {};
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
        ~UserError() {};
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        ~CommunicationError() {};
        const std::string getComponent() const;
};

#endif
