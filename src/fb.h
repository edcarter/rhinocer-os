#ifndef FB_H
#define FB_H

//frame buffer base address
extern char * fb;


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
enum fb_colour { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHT_GREY,
	DARK_GREY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN, 
	LIGHT_RED, LIGHT_MAGENTA, LIGHT_BROWN, WHITE }; 

/** fb_write_cell:
*  Writes a character with the given foreground and background to position i
*  in the framebuffer.
*
*  @param i  The location in the framebuffer
*  @param c  The character
*  @param fg The foreground color
*  @param bg The background color
*/
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

/** fb_clear:
*  Clears out the frame buffer with spaces
*  @param bg The background color
*/
void fb_clear(unsigned char bg);

/** fb_write_cell:
*  Writes a character with the given foreground and background to position i
*  in the framebuffer.
*
*  @param i  The location in the framebuffer
*  @param c  The string
*  @param fg The foreground color
*  @param bg The background color
*/
void fb_write_string(unsigned int i, char * str, unsigned char fg, unsigned char bg);

#endif /* FB_H */
