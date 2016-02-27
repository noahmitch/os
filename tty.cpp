
#include "tty.h"

uint8_t TTY::make_color(enum vgaColor fg, enum vgaColor bg) {
	return fg | bg << 4;
}

uint16_t TTY::make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

TTY::TTY (int address)
{
	int ad;
	if (address != -1)
	{
		ad = address;
	}
	buffer = (uint16_t*)ad;
	terminalColor = make_color(LIGHT_GREY, BLACK);
	row = 0;
	col = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			buffer[index] = make_vgaentry(' ', terminalColor);
		}
	}
}

void TTY::setColor (uint8_t color) {
	terminalColor = color;
}

void TTY::printCharAt (char c, uint8_t color, int x, int y)
{
	const size_t index = y * VGA_WIDTH + x;
	buffer[index] = make_vgaentry(c, color);
}

void TTY::printChar (char c)
{
	if (c == '\n')
	{
		row++;
		col = 0;
	}
	else if (c == '\t')
	{
		col+=4;
	}
	else
	{
		printCharAt (c, terminalColor, col, row);
		if (++col == VGA_WIDTH)
		{
			col = 0;
			row++;
			if (++row == VGA_HEIGHT)
			{
				row = 0;
			}
		}
	}
}

void TTY::printString (string input)
{
	for (int i = 0; i < input.size (); i++)
	{
		printChar (input[i]);
	}
}
