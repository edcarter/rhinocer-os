#include "fb.h"
#include "io.h"

unsigned short _cursor_position = 0;
unsigned char _default_bg = BLACK;
unsigned char _default_fg = WHITE;

char * fb = (char *) 0x000B8000;

/* Frame Buffer Dimensions */
#define FB_WIDTH    80
#define FB_HEIGHT   25

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

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
	fb_move_cursor(0);
}

/** fb_write_cell:
*  Writes a string with the given foreground and background to position i
*  in the framebuffer.
*
*  @param i    The location in the framebuffer
*  @param str  The string to write
*  @param len  The number of characters to write
*  @param fg   The foreground color
*  @param bg   The background color
*  @return     Number of characters written
*/
int fb_write_string(unsigned int i, const char * str, unsigned int len, unsigned char bg, unsigned char fg) {
	unsigned int index, fb_size = FB_WIDTH * FB_HEIGHT;
	for (index = 0; index < fb_size - i; index++) {
		if (str[index] == 0) break;
		if (index >= len) break;
		fb_write_cell(i + index, str[index], fg, bg);
	}
	return (int) index;
}

/** fb_move_cursor:
*  Moves the cursor of the framebuffer to the given position
*
*  @param pos The new position of the cursor
*/
void fb_move_cursor(unsigned short pos)
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT,    pos & 0x00FF);
	_cursor_position = pos;
}

/** fb_write:
*  Write to the framebuffer and advance the cursor
*  using the default background and foreground colours
*
*  @param buf The buffer holding charcters to write
*  @param len Number of characters to write
*  @return Number of characters written, -1 on error
*/
int fb_write(const char * buf, unsigned int len)
{
	int written = fb_write_string((unsigned int) _cursor_position, buf, len, _default_bg, _default_fg);
	fb_move_cursor(_cursor_position + written - 1);
	return written; 
}
