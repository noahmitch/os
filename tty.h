
#ifndef TTY_H
#define TTY_H
	#include "screen.h"
	#include "string.h"
	#include "memory.h"
#ifdef __cplusplus
	extern "C" {
#endif
	class TTY
	{
	public:
		TTY (int address=-1);
		void printCharAt (char c, uint8_t color, int x, int y);
		void printChar (char c);
		void printString (string input);
		void setColor (uint8_t color);
	private:
		uint8_t terminalColor;
		uint16_t *buffer;
		int row;
		int col;
		uint8_t make_color(enum vgaColor fg, enum vgaColor bg);
		uint16_t make_vgaentry (char c, uint8_t color);
	};
#ifdef __cplusplus
	}
#endif
#endif
