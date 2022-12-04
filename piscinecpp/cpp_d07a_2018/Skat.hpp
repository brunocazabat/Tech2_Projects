/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include <string>
#include <stdarg>

class Skat
{
    public:
        Skat(const std::string &name, int stimPaks);
        ~Skat();
        [...] stimPaks();
        const std::string &name();
        void shareStimPaks(int number , [...] stock ) ;
        void addStimPaks(unsigned int number ) ;
        void useStimPaks();
        void status();
    private:
        [...]
};