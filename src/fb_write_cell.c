#include "io.h"

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
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
	fb[i] = c;
	fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}
