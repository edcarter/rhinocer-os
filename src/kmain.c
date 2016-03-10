#include "fb.h"



void kmain() {
	fb_clear(BLACK);
	char version[64] = "rhinocer/os 0.1";
	fb_write_string(0, version, BLACK, WHITE);
	while (1) {

	}
}
