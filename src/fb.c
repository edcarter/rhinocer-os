#include "fb.h"

char * fb = (char *) 0x000B8000;

/* colour table for foreground and background
* Colour,   Value 
* Black,         0
* Blue,          1
* Green,         2
* Cyan,          3
* Red,           4
* Magenta,       5
* Brown,         6
* Light grey,    7
* Dark grey,     8
* Light blue,    9
* Light green,   10
* Light cyan,    11
* Light red,     12
* Light magenta, 13
* Light brown,   14
* White,         15
*/


/** fb_write_cell:
*  Writes a character with the given foreground and background to position i
*  in the framebuffer.
*
*  @param i  The location in the framebuffer
*  @param c  The character
*  @param fg The foreground color
*  @param bg The background color
*/
void fb_write_cell(unsigned int i, char c, unsigned char bg, unsigned char fg)
{
	i = i * 2;  //each cell is 16 bits
	fb[i] = c;
	fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/** fb_clear:
*  Clears out the frame buffer with spaces
*  @param bg The background color
*/
void fb_clear(unsigned char bg)
{
	//fb is 80 columns by 25 rows
	unsigned int i, fb_size = 80 * 50;
	for (i = 0; i < fb_size; i++) {
		//write space
		fb_write_cell(i, ' ', bg, bg);
	}
}

void fb_write_string(unsigned int i, char * str, unsigned char bg, unsigned char fg) {
	unsigned int index, fb_size = 80 * 50;
	for (index = 0; index < fb_size - i; index++) {
		if (str[index] == 0) break; //end of string
		fb_write_cell(i + index, str[index], fg, bg);
	}
}
