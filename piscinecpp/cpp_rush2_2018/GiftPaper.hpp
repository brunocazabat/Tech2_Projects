/*
** EPITECH PROJECT, 2019
** GiftPaper.hpp
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
	#define GIFTPAPER_HPP

#include "Wrap.hpp"

class GiftPaper : public Wrap {
	public:
		GiftPaper();
		~GiftPaper() override = default;

    void wrapMeThat(Object *obj);

	protected:
	private:
};

#endif /* !GIFTPAPER_HPP_ */
