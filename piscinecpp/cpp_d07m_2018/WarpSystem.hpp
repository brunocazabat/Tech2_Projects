/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef WARPSYSTEM_HPP_
	#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
        protected:
        private:
            bool _stability;
            bool isStable();
            void setStability(bool stability);
            QuantumReactor *_coreReactor;
    };
    class Core {
        public:
            Core();
            ~Core();
            char *checkReactor();
        protected:
        private:
    };
    class WarpSystem {
	    public:
		    WarpSystem();
		    ~WarpSystem();
	    protected:
	    private:
    };
};

#endif /* !WARPSYSTEM_HPP_ */