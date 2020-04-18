#include "leon8.h"

void matrix_init_kb(void) {
	matrix_init_user();
	backlight_level(3);
}
