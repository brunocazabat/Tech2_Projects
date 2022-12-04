/*
** EPITECH PROJECT, 2019
** Convoyer.hpp
** File description:
** Rush2 cpp pool
*/

#ifndef CONVOYERBELT_HPP_
	#define CONVOYERBELT_HPP_

#include "Object.hpp"
#include "IConveyorBelt.hpp"

	class PapaXmasConveyorBelt : public IConveyorBelt {
		public:
			PapaXmasConveyorBelt();
			~PapaXmasConveyorBelt();
			bool isFull();
			void putObject(Object *Object);
			Object *takeObject();
			void pressINBtn();
			Object pressOUTBtn();
			IConveyorBelt *createConveyorBelt();
			void ConveyorState();

		protected:
		private:
			Object *_obj;
			bool _full;
			bool _INButton;
			bool _OUTButton;
};


#endif /* !CONVOYERBELT_HPP_ */
