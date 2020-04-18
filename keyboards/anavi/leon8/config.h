/*
Copyright 2020 Leon Anavi <leon@anavi.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCEEB
#define PRODUCT_ID      0x0007
#define DEVICE_VER      0x0001
#define MANUFACTURER    ANAVI
#define PRODUCT         Leon8
#define DESCRIPTION     8 key microswitch board

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *                  NO_DIODE = switches are directly connected to AVR pins
 *
*/
// #define MATRIX_ROW_PINS { D0, D5 }
// #define MATRIX_COL_PINS { F1, F0, B0 }
#define DIRECT_PINS {   \
    { D4, C6, E6, B4 }, \
    { B5, F7, F6, F5 } \
}

#define BACKLIGHT_PIN D7
#define BACKLIGHT_BREATHING
#define BACKLIGHT_LEVELS 3

#define UNUSED_PINS

/* ws2812B RGB LED */
#define RGB_DI_PIN F4
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 8
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 10
#define RGBLIGHT_LIMIT_VAL 255

#ifdef OLED_DRIVER_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_DISABLE_TIMEOUT
#    define OLED_FONT_H "keyboards/crkbd/keymaps/drashna/glcdfont.c"
#endif
