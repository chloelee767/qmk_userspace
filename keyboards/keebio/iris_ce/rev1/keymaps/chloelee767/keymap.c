// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "features/caps_word.h"

// note: make lockable layers lower numbered
// so that we can use the higher layers if needed
enum custom_layers {
  _QWERTY, // base layer
  _LEFT_NUMNAV, // left side of NUMNAV layer
  _RIGHT_NUMNAV, // right side of NUMNAV layer
  _NUMNAV,
  _SYMBOL,
  _MULTIMEDIA
};

enum my_keycodes {
  UKC_NUM_WORD_TOGGLE = SAFE_RANGE,
  UKC_NUM_LOCK_TOGGLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] =
  LAYOUT(
    /* Number Row */
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
    KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
    /* Qwerty Row */
    QK_CAPS_WORD_TOGGLE, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_Y, KC_U, KC_I, KC_O, KC_P, QK_CAPS_WORD_TOGGLE,
    /* Home Row */
    KC_ESC, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), LCAG_T(KC_G),
    LCAG_T(KC_H), LCTL_T(KC_J), LALT_T(KC_K), LGUI_T(KC_L), LSFT_T(KC_SCLN), KC_QUOT,
    /* Zxc Row (Left) */
    OSM(MOD_LGUI), LT(_RIGHT_NUMNAV,KC_Z), LT(_RIGHT_NUMNAV,KC_X), LT(_RIGHT_NUMNAV,KC_C), LT(_RIGHT_NUMNAV,KC_V), KC_B,
    /* Top Thumb Keys */
    MO(_MULTIMEDIA), MO(_MULTIMEDIA),
    /* Zxc Row (Right) */
    KC_N, LT(_LEFT_NUMNAV,KC_M), LT(_LEFT_NUMNAV,KC_COMM), LT(_LEFT_NUMNAV,KC_DOT), LT(_LEFT_NUMNAV,KC_SLSH), KC_MINS,
    /* Bottom Row */
    LT(_NUMNAV,KC_DEL), LT(_SYMBOL,KC_BSPC), LT(_NUMNAV,KC_TAB),
    LT(_SYMBOL,KC_ENT), LT(_NUMNAV,KC_SPC), LT(_MULTIMEDIA,KC_BSPC)
  ),

  [_SYMBOL] =
  LAYOUT(
    /* Number Row */
    _______, _______, _______, _______, _______, _______,
    _______, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, _______, _______, _______,
    /* Qwerty Row */
    _______, XXXXXXX, KC_PPLS, KC_EQL, KC_GRV, XXXXXXX, /* Don't use KC_PEQL (numpad equal) for compatiblity with windows */
    KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, XXXXXXX,
    /* Home Row */
    _______, KC_EXLM, KC_PERC, KC_MINS, KC_COLN, KC_TILD,
    KC_DLR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_DQUO,
    /* Zxc Row (Left) */
    _______, KC_AT, KC_HASH, KC_UNDS, KC_AT, XXXXXXX,
    /* Top Thumb Keys */
    _______, _______,
    /* Zxc Row (Right) */
    KC_0, KC_EQL, KC_LT, KC_GT, KC_QUES, KC_QUOT,
    /* Bottom Row */
    _______, _______, _______,
    _______, _______, _______
  ),

  [_NUMNAV] =
  LAYOUT(
    /* Number Row */
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    /* Qwerty Row */
    XXXXXXX, XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, KC_HOME,
    KC_EQL, KC_1, KC_2, KC_3, XXXXXXX, KC_F12,
    /* Home Row */
    XXXXXXX, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    KC_MINS, KC_4, KC_5, KC_6, KC_DOT, KC_COMM,
    /* Zxc Row (Left) */
    XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,
    /* Top Thumb Keys */
    _______, _______,
    /* Zxc Row (Right) */
    KC_PLUS, KC_7, KC_8, KC_9, KC_SLSH, KC_ASTR,
    /* Bottom Row */
    _______, _______, _______,
    _______, _______, KC_0
  ),

  [_LEFT_NUMNAV] = LAYOUT(
    /* Number Row */
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
    _______, _______, _______, _______, _______, _______,
    /* Qwerty Row */
    XXXXXXX, XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, KC_HOME,
    _______, _______, _______, _______, _______, _______,
    /* Home Row */
    XXXXXXX, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    _______, _______, _______, _______, _______, _______,
    /* Zxc Row (Left) */
    XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,
    /* Top Thumb Keys */
    _______, _______,
    /* Zxc Row (Right) */
    _______, _______, _______, _______, _______, _______,
    /* Bottom Row */
    _______, _______, _______,
    _______, _______, _______
  ),

  [_RIGHT_NUMNAV] = LAYOUT(
    /* Number Row */
    _______, _______, _______, _______, _______, _______,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    /* Qwerty Row */
    _______, _______, _______, _______, _______, _______,
    KC_EQL, KC_1, KC_2, KC_3, XXXXXXX, KC_F12,
    /* Home Row */
    _______, _______, _______, _______, _______, _______,
    KC_MINS, KC_4, KC_5, KC_6, KC_DOT, KC_COMM,
    /* Zxc Row (Left) */
    _______, _______, _______, _______, _______, _______,
    /* Top Thumb Keys */
    _______, _______,
    /* Zxc Row (Right) */
    KC_PLUS, KC_7, KC_8, KC_9, KC_SLSH, KC_ASTR,
    /* Bottom Row */
    _______, _______, _______,
    _______, _______, KC_0
  ),

  [_MULTIMEDIA] =
  LAYOUT(
    /* Number Row */
    QK_BOOT, XXXXXXX, RM_TOGG, RM_VALD, RM_VALU, QK_CLEAR_EEPROM,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    /* Qwerty Row */
    XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /* Home Row */
    XXXXXXX, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /* Zxc Row (Left) */
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,
    /* Top Thumb Keys */
    _______, _______,
    /* Zxc Row (Right) */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /* Bottom Row */
    _______, _______, _______,
    _______, _______, _______
  )

};

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Allow same-hand holds for thumb key holds.
  if (tap_hold_record->event.key.row == 4 || tap_hold_record->event.key.row == 9) {
    return true;
  }

  // Allow same hands with holds pressing the thumb keys.
  if (other_record->event.key.row == 4 || other_record->event.key.row == 9) {
    return true;
  }

  // TODO Allow same hand for zxc row combos

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  // Return 0 for certain keys if we want to bypass achordion.

  // Return same as tapping term instead of the default 1000ms to
  // allow us to use single hand tap-holds with the mouse.
  return TAPPING_TERM;
}

bool apply_mod_if_holding(uint16_t mod_keycode, keyrecord_t* record) {
  if (!record->tap.count) { // if holding
    if (record->event.pressed) { // on hold press
      register_mods(MOD_BIT(mod_keycode));
    } else { // on hold release
      unregister_mods(MOD_BIT(mod_keycode));
    }
  }
  return true; // Continue normal handling
}

bool is_layer_locked_arr [] = {false, false, false, false, false, false, false, false};

bool is_layer_locked(uint8_t layer) {
  uint8_t n = sizeof(is_layer_locked_arr) / sizeof(is_layer_locked_arr[0]);

  // ensure array index is within bounds
  if (layer >= n) {
    return false;
  }

  return is_layer_locked_arr[layer];
}

void toggle_layer_lock(uint8_t layer) {
  uint8_t n = sizeof(is_layer_locked_arr) / sizeof(is_layer_locked_arr[0]);

  // ensure array index is within bounds
  if (layer >= n) {
    return;
  }

  caps_word_off();
  layer_clear();
  // set all other layers to false
  for (uint8_t i = 0; i < n; i++) {
    if (i != layer) is_layer_locked_arr[i] = false;
  }

  is_layer_locked_arr[layer] = !is_layer_locked_arr[layer];
  if (is_layer_locked_arr[layer]) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
}

void turn_off_all_layer_locks(void) {
  layer_clear();
  uint8_t n = sizeof(is_layer_locked_arr) / sizeof(is_layer_locked_arr[0]);
  for (uint8_t i = 0; i < n; i++) {
    is_layer_locked_arr[i] = false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

  // Custom code goes after achordion

  switch (keycode) {
  // left numnav-mods layer
  case LT(_LEFT_NUMNAV,KC_DOT):
    // Behave as KC_DOT/KC_O on tap, LM(_LEFT_NUMNAV,MOD_LGUI) on hold
    return apply_mod_if_holding(KC_LGUI, record);
  case LT(_LEFT_NUMNAV,KC_COMM):
    return apply_mod_if_holding(KC_LALT, record);
  case LT(_LEFT_NUMNAV,KC_M):
    return apply_mod_if_holding(KC_LCTL, record);
  case LT(_LEFT_NUMNAV,KC_SLSH):
    return apply_mod_if_holding(KC_LSFT, record);

  // right numnav-mods layer
  case LT(_RIGHT_NUMNAV,KC_X):
    // Behave as KC_DOT/KC_O on tap, LM(_RIGHT_NUMNAV,MOD_LGUI) on hold
    return apply_mod_if_holding(KC_LGUI, record);
  case LT(_RIGHT_NUMNAV,KC_C):
    return apply_mod_if_holding(KC_LALT, record);
  case LT(_RIGHT_NUMNAV,KC_V):
    return apply_mod_if_holding(KC_LCTL, record);
  case LT(_RIGHT_NUMNAV,KC_Z):
    return apply_mod_if_holding(KC_LSFT, record);

    // caps word / num word
  case QK_CAPS_WORD_TOGGLE:
    if (record->event.pressed) {
      toggle_caps_word_mode(CAPS_WORD_MODE_DEFAULT);
      return false;
    }
    break;
  case UKC_NUM_WORD_TOGGLE:
    if (record->event.pressed) {
      toggle_caps_word_mode(CWMODE_NUMBER);
      return false;
    }
    break;

    // layer locks
  case UKC_NUM_LOCK_TOGGLE:
    if (record->event.pressed) {
      toggle_layer_lock(_NUMNAV);
      return false;
    }
    break;
  }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

// Combos

// Note: we must use the entire keycode.
// Eg. tap-hold keycodes like LCTL_T(KC_J) won't work if we just use KC_J
const uint16_t PROGMEM combo_uj[] = {KC_U, LCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo_ik[] = {KC_I, LALT_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_ol[] = {KC_O, LGUI_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_rf[] = {KC_R, LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_de[] = {LALT_T(KC_D), KC_E, COMBO_END};
const uint16_t PROGMEM combo_78[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_89[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_23[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_34[] = {KC_3, KC_4, COMBO_END};
// function row combos
const uint16_t PROGMEM combo_f1[] = {KC_1, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_f2[] = {KC_2, KC_W, COMBO_END};
const uint16_t PROGMEM combo_f3[] = {KC_3, KC_E, COMBO_END};
const uint16_t PROGMEM combo_f4[] = {KC_4, KC_R, COMBO_END};
const uint16_t PROGMEM combo_f5[] = {KC_5, KC_T, COMBO_END};
const uint16_t PROGMEM combo_f6[] = {KC_6, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_f7[] = {KC_7, KC_U, COMBO_END};
const uint16_t PROGMEM combo_f8[] = {KC_8, KC_I, COMBO_END};
const uint16_t PROGMEM combo_f9[] = {KC_9, KC_O, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_0, KC_P, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_EQL, QK_CAPS_WORD_TOGGLE, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {QK_CAPS_WORD_TOGGLE, KC_QUOT, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_uj, KC_LEFT_BRACKET),
  COMBO(combo_ik, KC_RIGHT_BRACKET),
  COMBO(combo_ol, KC_BSLS),
  COMBO(combo_rf, KC_GRV),
  COMBO(combo_de, KC_TILD),

  COMBO(combo_23, UKC_NUM_WORD_TOGGLE),
  COMBO(combo_89, UKC_NUM_WORD_TOGGLE),
  COMBO(combo_34, UKC_NUM_LOCK_TOGGLE),
  COMBO(combo_78, UKC_NUM_LOCK_TOGGLE),

  COMBO(combo_f1, KC_F1),
  COMBO(combo_f2, KC_F2),
  COMBO(combo_f3, KC_F3),
  COMBO(combo_f4, KC_F4),
  COMBO(combo_f5, KC_F5),
  COMBO(combo_f6, KC_F6),
  COMBO(combo_f7, KC_F7),
  COMBO(combo_f8, KC_F8),
  COMBO(combo_f9, KC_F9),
  COMBO(combo_f10, KC_F10),
  COMBO(combo_f11, KC_F11),
  COMBO(combo_f12, KC_F12),
};

// Caps word

// Callback when caps word is activated or deactivated
void caps_word_set_user(bool active) {
  cw_caps_word_set_user(active);
  turn_off_all_layer_locks();
  if (active) {
    // Do something when Caps Word activates.
    if (g_caps_word_mode == CWMODE_NUMBER) {
      layer_on(_RIGHT_NUMNAV);
    }
  } else {
    // Do something when Caps Word deactivates.
  }
}

// RGB

hsv_t hsv_limit_brightness(hsv_t hsv) {
  // allow us to have no led by default and only have them for layer indication
  // by setting the brightness to 0
  uint8_t current_val = rgb_matrix_get_val();
  if (current_val == 0) {
    hsv.v = RGB_MATRIX_VAL_STEP;
  } else {
    hsv.v = current_val;
  }
  return hsv;
}

void set_all_leds(uint8_t led_min, uint8_t led_max, rgb_t rgb) {
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}

// row and col are matrix positions, which can be found in the keymap.json file.
// you can use scripts/visualize_matrix.py to visualize it on the keyboard.
void set_rgb(uint8_t row, uint8_t col, rgb_t rgb) {
  if (row >= MATRIX_ROWS || col >= MATRIX_COLS) {
    return;
  }

  uint8_t idx = g_led_config.matrix_co[row][col];
  rgb_matrix_set_color(idx, rgb.r, rgb.g, rgb.b);
}

rgb_t get_default_rgb_color(void) {
  uint8_t current_val = rgb_matrix_get_val();
  if (current_val == 0) {
    return (rgb_t){RGB_BLACK};
  }

  hsv_t hsv_white = {HSV_WHITE};
  hsv_white.v = current_val;
  rgb_t rgb_white = hsv_to_rgb(hsv_white);
  return rgb_white;
}

void set_left_numnav_leds(rgb_t rgb) {
  set_rgb(1, 3, rgb); // up arrow
  set_rgb(2, 2, rgb); // left arrow
  set_rgb(2, 3, rgb); // down arrow
  set_rgb(2, 4, rgb); // right arrow

  // FIXME: workaround for LED mirroring bug - setting LEDs at certain positions on the left half
  // causes LEDs at the corresponding mirrored positions on the right half to also light up.
  // We need to explicitly reset the right side LEDs back to the default color.
  // Note that the same issue doesn't occur when setting right side LEDs.
  rgb_t rgb_default = get_default_rgb_color();
  set_rgb(6, 3, rgb_default);
  set_rgb(7, 2, rgb_default);
  set_rgb(7, 3, rgb_default);
  set_rgb(7, 4, rgb_default);
}

void set_right_numnav_leds(rgb_t rgb) {
  for (uint8_t i = 6; i <= 8; i++) {
    for (uint8_t j = 2; j <= 4; j++) {
      set_rgb(i, j, rgb);
    }
  }
}
// TODO fix - leds are mirrored on both halves
void set_testing_leds(uint8_t led_min, uint8_t led_max) {
  hsv_t hsv_red = {HSV_RED};
  hsv_t hsv_blue = {HSV_BLUE};
  hsv_t hsv_green = {HSV_GREEN};
  hsv_t hsv_yellow = {HSV_YELLOW};

  /* hsv_t hsv_white = {HSV_WHITE}; */
  /* set_all_leds(led_min, led_max, hsv_to_rgb(hsv_limit_brightness(hsv_white))); */

  set_rgb(0, 0, hsv_to_rgb(hsv_limit_brightness(hsv_red)));
  set_rgb(0, 1, hsv_to_rgb(hsv_limit_brightness(hsv_red)));
  set_rgb(0, 2, hsv_to_rgb(hsv_limit_brightness(hsv_red)));

  set_rgb(0, 3, hsv_to_rgb(hsv_limit_brightness(hsv_blue)));
  set_rgb(0, 4, hsv_to_rgb(hsv_limit_brightness(hsv_blue)));
  set_rgb(0, 5, hsv_to_rgb(hsv_limit_brightness(hsv_blue)));

  set_rgb(1, 0, hsv_to_rgb(hsv_limit_brightness(hsv_green)));
  set_rgb(1, 1, hsv_to_rgb(hsv_limit_brightness(hsv_green)));
  set_rgb(1, 2, hsv_to_rgb(hsv_limit_brightness(hsv_green)));

  // n, m
  // this isn't mirrored
  set_rgb(8, 4, hsv_to_rgb(hsv_limit_brightness(hsv_yellow)));
  set_rgb(8, 5, hsv_to_rgb(hsv_limit_brightness(hsv_yellow)));
}

void set_multimedia_layer_leds(void) {
  hsv_t hsv = {HSV_PURPLE};
  rgb_t rgb = hsv_to_rgb(hsv_limit_brightness(hsv));

  set_rgb(1, 3, rgb);
  set_rgb(1, 4, rgb);

  // FIXME: workaround for mirroring bug (see earlier comment for details)
  rgb_t rgb_default = get_default_rgb_color();
  set_rgb(6, 3, rgb_default);
  set_rgb(6, 4, rgb_default);
}

void set_caps_word_leds(void) {
  hsv_t hsv = {HSV_ORANGE};
  rgb_t rgb = hsv_to_rgb(hsv_limit_brightness(hsv));
  // light up caps word buttons
  set_rgb(1, 0, rgb);
  set_rgb(6, 0, rgb);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  hsv_t hsv = {HSV_BLUE};
  rgb_t rgb = hsv_to_rgb(hsv_limit_brightness(hsv));
  switch(get_highest_layer(layer_state|default_layer_state)) {
  case _NUMNAV:
    set_left_numnav_leds(rgb); // set left half first
    set_right_numnav_leds(rgb);
    break;
  case _LEFT_NUMNAV:
    set_left_numnav_leds(rgb);
    break;
  case _RIGHT_NUMNAV:
    set_right_numnav_leds(rgb);
    break;
  case _MULTIMEDIA:
    set_multimedia_layer_leds();
    break;
  default:
    break;
  }

  if (is_caps_word_on()) {
    set_caps_word_leds();
  }

  return false;
}

