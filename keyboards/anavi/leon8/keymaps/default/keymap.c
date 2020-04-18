#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FN 1

#define KC_X0 LT(_FN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,
     RGB_MOD, RGB_SAD, RGB_HUD, RGB_VAD
  ),

  [_FN] = LAYOUT(
     KC_F,    _______, RGB_HUI, _______,
     RGB_TOG, RGB_MOD, RGB_HUD, _______
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_ln_P(PSTR("Mini Keyboard"), false);
  oled_write_P(PSTR("Active layer:"), false);

  switch (get_highest_layer(layer_state)) {
    case _MAIN:
      oled_write_ln_P(PSTR("Main"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("FN"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("N/A"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(PSTR("Num Lock: "), false);
  oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("On") : PSTR("Off"), false);
  oled_write_P(PSTR("Caps Lock: "), false);
  oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("On") : PSTR("Off"), false);
  oled_write_P(PSTR("Scroll Lock: "), false);
  oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("On") : PSTR("Off"), false);
  oled_write_P(PSTR("Backlit: "), false);
  oled_write_ln_P(is_backlight_enabled() ? PSTR("On") : PSTR("Off"), false);
  oled_write_ln_P(PSTR("RGB Lighting: "), false);
  static char buffer[26] = {0};
  snprintf(buffer, sizeof(buffer), "m:%d h:%d s:%d v:%d", rgblight_get_mode(), rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
  oled_write_ln(buffer, false);
}
#endif
