/*
** EPITECH PROJECT, 2019
** Warp
** File description:
** Warp
*/

#ifndef WARPSYSTEM_HPP_
	#define WARPSYSTEM_HPP_

#include <iomanip>
#include <iostream>
#include <string>

namespace WarpSystem
{
    class QuantumReactor {
    	public:
	    	QuantumReactor();
		    ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);

    	protected:
	    private:
            bool _stability;
    };
    
    class Core {
    	public:
	    	Core(QuantumReactor *coreReactor);
		    ~Core();
            QuantumReactor *checkReactor();

    	protected:
	    private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
