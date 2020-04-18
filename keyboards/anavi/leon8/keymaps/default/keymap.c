#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FN 1

#define KC_X0 LT(_FN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
     RGB_TOG, BL_ON, BL_OFF, BL_BRTG,
     RGB_MODE_RAINBOW, LCTL(KC_TAB), LCTL(KC_A), BL_STEP
  ),

  [_FN] = LAYOUT(
     KC_F,    _______, RGB_HUI, _______,
     RGB_TOG, RGB_MOD, RGB_HUD, _______
  )
};
