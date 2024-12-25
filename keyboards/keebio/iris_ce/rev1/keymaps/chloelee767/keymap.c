// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum custom_layers {
_QWERTY,
_SYMBOL,
_NUMNAV,
_NUM,
_NAV,
_FNKEY,
_MULTIMEDIA
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
KC_ESC, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,
KC_H, LCTL_T(KC_J), LALT_T(KC_K), LGUI_T(KC_L), LSFT_T(KC_SCLN), KC_QUOT,
/* Zxc Row (Left) */
MO(_MULTIMEDIA), LT(_NAV,KC_Z), LT(_NAV,KC_X), LT(_NAV,KC_C), LT(_NAV,KC_V), KC_B,
/* Top Thumb Keys */
XXXXXXX, XXXXXXX,
/* Zxc Row (Right) */
KC_N, LT(_NUM,KC_M), LT(_NUM,KC_COMM), LT(_NUM,KC_DOT), LT(_NUM,KC_SLSH), MO(_MULTIMEDIA),
/* Bottom Row */
LT(_FNKEY,KC_DEL), LT(_SYMBOL,KC_BSPC), LT(_NUMNAV,KC_TAB),
LT(_SYMBOL,KC_ENT), LT(_NUMNAV,KC_SPC), LT(_FNKEY,KC_BSPC)
),

[_SYMBOL] =
LAYOUT(
/* Number Row */
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, XXXXXXX, XXXXXXX, XXXXXXX,
/* Qwerty Row */
_______, XXXXXXX, KC_PPLS, KC_EQL, XXXXXXX, KC_GRV, /* Don't use KC_PEQL (numpad equal) for compatiblity with windows */
KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, XXXXXXX,
/* Home Row */
_______, KC_EXLM, KC_PERC, KC_MINS, KC_COLN, KC_TILD,
KC_DLR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_DQUO,
/* Zxc Row (Left) */
_______, KC_AT, KC_HASH, KC_UNDS, XXXXXXX, XXXXXXX,
/* Top Thumb Keys */
_______, _______,
/* Zxc Row (Right) */
KC_BSLS, KC_EQL, KC_LT, KC_GT, KC_QUES, KC_QUOT,
/* Bottom Row */
_______, _______, _______,
_______, _______, _______
),

[_NUMNAV] =
LAYOUT(
/* Number Row */
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX,
/* Qwerty Row */
KC_PLUS, KC_MINS, KC_1, KC_2, KC_3, KC_4,
KC_HOME, KC_PGUP, KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
/* Home Row */
KC_COMM, KC_DOT, KC_4, KC_5, KC_6, KC_7,
KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI, XXXXXXX,
/* Zxc Row (Left) */
KC_ASTR, KC_SLSH, KC_7, KC_8, KC_9, KC_BSLS,
/* Top Thumb Keys */
_______, _______,
/* Zxc Row (Right) */
XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,
/* Bottom Row */
KC_EQL, KC_0, _______,
_______, _______, _______
),

[_NUM] = LAYOUT(
/* Number Row */
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
_______, _______, _______, _______, _______, _______,
/* Qwerty Row */
KC_PLUS, KC_MINS, KC_1, KC_2, KC_3, KC_4,
_______, _______, _______, _______, _______, _______,
/* Home Row */
KC_COMM, KC_DOT, KC_4, KC_5, KC_6, KC_7,
_______, _______, _______, _______, _______, _______,
/* Zxc Row (Left) */
KC_ASTR, KC_SLSH, KC_7, KC_8, KC_9, KC_BSLS,
/* Top Thumb Keys */
_______, _______,
/* Zxc Row (Right) */
_______, _______, _______, _______, _______, _______,
/* Bottom Row */
KC_EQL, KC_0, _______,
_______, _______, _______
),

[_NAV] = LAYOUT(
/* Number Row */
_______, _______, _______, _______, _______, _______,
XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX,
/* Qwerty Row */
_______, _______, _______, _______, _______, _______,
KC_HOME, KC_PGUP, KC_UP, KC_PGDN, XXXXXXX, XXXXXXX,
/* Home Row */
_______, _______, _______, _______, _______, _______,
KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI, XXXXXXX,
/* Zxc Row (Left) */
_______, _______, _______, _______, _______, _______,
/* Top Thumb Keys */
_______, _______,
/* Zxc Row (Right) */
XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,
/* Bottom Row */
_______, _______, _______,
_______, _______, _______
),

[_FNKEY] =
LAYOUT(
/* Number Row */
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
/* Qwerty Row */
XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
/* Home Row */
XXXXXXX, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,
/* Zxc Row (Left) */
QK_BOOT, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,
/* Top Thumb Keys */
_______, _______,
/* Zxc Row (Right) */
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
/* Bottom Row */
_______, _______, _______,
_______, _______, _______
),

[_MULTIMEDIA] =
LAYOUT(
/* Number Row */
RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_CLEAR_EEPROM,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
/* Qwerty Row */
RM_VALD, RM_VALU, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

  // Custom code goes after achordion

  switch (keycode) {
    // num-mods layer
    case LT(_NUM,KC_DOT):
    case LT(_NUM,KC_O):
      // Behave as KC_DOT/KC_O on tap, LM(_NUM,MOD_LGUI) on hold
      return apply_mod_if_holding(KC_LGUI, record);
    case LT(_NUM,KC_COMM):
      return apply_mod_if_holding(KC_LALT, record);
    case LT(_NUM,KC_M):
      return apply_mod_if_holding(KC_LCTL, record);
    case LT(_NUM,KC_SLSH):
      return apply_mod_if_holding(KC_LSFT, record);

    // nav-mods layer
    case LT(_NAV,KC_X):
    case LT(_NAV,KC_W):
      // Behave as KC_DOT/KC_O on tap, LM(_NAV,MOD_LGUI) on hold
      return apply_mod_if_holding(KC_LGUI, record);
    case LT(_NAV,KC_C):
      return apply_mod_if_holding(KC_LALT, record);
    case LT(_NAV,KC_V):
      return apply_mod_if_holding(KC_LCTL, record);
    case LT(_NAV,KC_Z):
      return apply_mod_if_holding(KC_LSFT, record);
  }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

// Combos

const uint16_t PROGMEM uj_combo[] = {KC_U, LCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM ik_combo[] = {KC_I, LALT_T(KC_K), COMBO_END};
const uint16_t PROGMEM ol_combo[] = {KC_O, LGUI_T(KC_L), COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, LCTL_T(KC_F), COMBO_END};
combo_t key_combos[] = {
  COMBO(uj_combo, KC_LEFT_BRACKET),
  COMBO(ik_combo, KC_RIGHT_BRACKET),
  COMBO(ol_combo, KC_BSLS),
  COMBO(io_combo, KC_BSPC),
  COMBO(op_combo, KC_DEL),
  COMBO(rf_combo, KC_GRV),
};

// RGB

hsv_t hsv_limit_brightness(hsv_t hsv) {
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  return hsv;
}

// FIXME led positions are wrong
void set_numlayer_leds(uint8_t led_min, uint8_t led_max, rgb_t rgb) {
  uint8_t num_leds[] = {14, 15, 16, 26, 27, 28, 38, 39, 40};
  size_t n = sizeof(num_leds) / sizeof(num_leds[0]);

  for (uint8_t i = 0; i < n; i++) {
    uint8_t led = led_min + num_leds[i];
    rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
    /* if (led < led_max) { */
    /*   rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b); */
    /* } */
  }
}

void set_all_leds(uint8_t led_min, uint8_t led_max, rgb_t rgb) {
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}

void set_rgb(uint8_t row, uint8_t col, rgb_t rgb) {
  if (row >= MATRIX_ROWS || col >= MATRIX_COLS) {
    return;
  }

  uint8_t idx = g_led_config.matrix_co[row][col];
  rgb_matrix_set_color(idx, rgb.r, rgb.g, rgb.b);
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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  hsv_t hsv = {HSV_WHITE};
  switch(get_highest_layer(layer_state|default_layer_state)) {
  case _NUMNAV:
    /* hsv = (hsv_t){HSV_GREEN}; */
    /* set_numlayer_leds(led_min, led_max, hsv_to_rgb(hsv_limit_brightness(hsv))); */
    set_testing_leds(led_min, led_max);
    break;
  case _SYMBOL:
    hsv = (hsv_t){HSV_BLUE};
    set_all_leds(led_min, led_max, hsv_to_rgb(hsv_limit_brightness(hsv)));
    break;
  case _QWERTY:
    /* hsv = (hsv_t){HSV_WHITE}; */
    /* set_all_leds(led_min, led_max, hsv_to_rgb(hsv_limit_brightness(hsv))); */
    break;
  default:
    /* hsv = (hsv_t){HSV_WHITE}; */
    /* set_all_leds(led_min, led_max, hsv_to_rgb(hsv_limit_brightness(hsv))); */
    break;
  }

  return false;
}

