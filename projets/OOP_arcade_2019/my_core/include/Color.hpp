/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

namespace Arcade {
	class Color {
	public:
		Color(unsigned char red = 0, unsigned char green = 0,
			unsigned char blue = 0, unsigned char alpha = 0);
		~Color() = default;
		void setColor(unsigned char red = 0, unsigned char green = 0,
			unsigned char blue = 0, unsigned char alpha = 0);
		unsigned char getRed() const;
		unsigned char getGreen() const;
		unsigned char getBlue() const;
		unsigned char getAlpha() const;
		void setRed(unsigned char red);
		void setGreen(unsigned char green);
		void setBlue(unsigned char blue);
		void setAlpha(unsigned char alpha);
		operator unsigned char *();
		bool operator!=(const Color &ocolor);
		bool operator==(const Color &ocolor);

	private:
		unsigned char _red;
		unsigned char _green;
		unsigned char _blue;
		unsigned char _alpha;
	};
};
